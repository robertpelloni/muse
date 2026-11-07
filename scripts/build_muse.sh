#!/usr/bin/env bash
#=============================================================================
#  MusE Unified Modern Build Runner
#  Provides streamlined, non-destructive configuration, compilation, and install.
#=============================================================================
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
SRC_DIR="${REPO_ROOT}/src"
BUILD_DIR="${REPO_ROOT}/build"

BUILD_TYPE="Release"
CLEAN_BUILD=false
CHECK_DEPS=false
NUM_JOBS=$(nproc 2>/dev/null || echo "4")
INSTALL_PREFIX="/usr/local"
EXTRA_CMAKE_ARGS=()

show_help() {
  cat << EOF
MusE Unified Build Runner

Usage: $0 [options]

Options:
  -h, --help            Show this help message and exit
  -c, --clean           Perform a clean build (removes build directory first)
  -d, --debug           Build with Debug configuration (default: Release)
  -r, --release         Build with Release configuration (default)
  -j, --jobs N          Number of concurrent compilation jobs (default: ${NUM_JOBS})
  --prefix PATH         Installation prefix (default: /usr/local)
  --check-deps          Verify required and optional dependencies without building
  --cmake-arg ARG       Pass additional argument to CMake configure step

Examples:
  $0 --release --jobs 8
  $0 --clean --debug
  $0 --check-deps
EOF
}

check_dependencies() {
  echo "=== MusE Dependency Checker ==="
  local MISSING=0

  for cmd in cmake gcc g++ pkg-config make; do
    if command -v "$cmd" >/dev/null 2>&1; then
      echo "  [OK] $cmd found: $(command -v "$cmd")"
    else
      echo "  [MISSING] $cmd not found!"
      MISSING=$((MISSING + 1))
    fi
  done

  # Check CMake ECM (Extra CMake Modules)
  if pkg-config --exists ecm 2>/dev/null || [ -d "/usr/share/ECM/cmake" ] || [ -d "/usr/lib/x86_64-linux-gnu/cmake/ECM" ]; then
    echo "  [OK] Extra CMake Modules (ECM) detected."
  else
    echo "  [INFO] Extra CMake Modules (ECM) not detected via standard pkg-config/paths."
  fi

  # Check Qt
  if pkg-config --exists Qt5Core 2>/dev/null; then
    echo "  [OK] Qt5 detected: $(pkg-config --modversion Qt5Core)"
  else
    echo "  [INFO] Qt5Core pkg-config not detected. Check system Qt5 dev packages."
  fi

  # Check audio backends
  for lib in alsa jack sndfile samplerate fluidsynth; do
    if pkg-config --exists "$lib" 2>/dev/null; then
      echo "  [OK] Library detected: $lib"
    else
      echo "  [INFO] Library not found via pkg-config: $lib"
    fi
  done

  if [ "$MISSING" -gt 0 ]; then
    echo "Warning: $MISSING essential build tools are missing."
    return 1
  else
    echo "All core build tools found."
    return 0
  fi
}

# Parse options
while [[ $# -gt 0 ]]; do
  case "$1" in
    -h|--help)
      show_help
      exit 0
      ;;
    -c|--clean)
      CLEAN_BUILD=true
      shift
      ;;
    -d|--debug)
      BUILD_TYPE="Debug"
      shift
      ;;
    -r|--release)
      BUILD_TYPE="Release"
      shift
      ;;
    -j|--jobs)
      NUM_JOBS="$2"
      shift 2
      ;;
    --prefix)
      INSTALL_PREFIX="$2"
      shift 2
      ;;
    --check-deps)
      CHECK_DEPS=true
      shift
      ;;
    --cmake-arg)
      EXTRA_CMAKE_ARGS+=("$2")
      shift 2
      ;;
    *)
      echo "Unknown option: $1"
      show_help
      exit 1
      ;;
  esac
done

if [ "$CHECK_DEPS" = true ]; then
  check_dependencies
  exit 0
fi

echo "=============================================="
echo " Starting MusE Build (${BUILD_TYPE})"
echo " Parallel Jobs: ${NUM_JOBS}"
echo " Install Prefix: ${INSTALL_PREFIX}"
echo " Source Dir: ${SRC_DIR}"
echo " Build Dir: ${BUILD_DIR}"
echo "=============================================="

if [ "$CLEAN_BUILD" = true ] && [ -d "${BUILD_DIR}" ]; then
  echo "Cleaning existing build directory: ${BUILD_DIR}"
  rm -rf "${BUILD_DIR}"
fi

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

echo "Configuring with CMake..."
cmake "${SRC_DIR}" \
  -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
  -DCMAKE_INSTALL_PREFIX="${INSTALL_PREFIX}" \
  -DMODULES_BUILD_STATIC=ON \
  "${EXTRA_CMAKE_ARGS[@]}"

echo "Building MusE with ${NUM_JOBS} jobs..."
cmake --build . --parallel "${NUM_JOBS}"

echo "=============================================="
echo " MusE Build Completed Successfully!"
echo " To install, run: sudo cmake --install ${BUILD_DIR}"
echo "=============================================="
