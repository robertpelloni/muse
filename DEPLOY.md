# MusE Build & Deployment Guide (DEPLOY.md)

Detailed instructions for configuring, building, testing, packaging, and deploying MusE.

---

## 1. Prerequisites & Dependencies

### Ubuntu / Debian (22.04 LTS / 24.04 LTS)
```bash
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    extra-cmake-modules \
    pkg-config \
    ninja-build \
    qtbase5-dev \
    qttools5-dev \
    qttools5-dev-tools \
    libqt5svg5-dev \
    libjack-jackd2-dev \
    libasound2-dev \
    libsndfile1-dev \
    libsamplerate0-dev \
    libfluidsynth-dev \
    libinstpatch-dev \
    librubberband-dev \
    liblo-dev \
    dssi-dev \
    ladspa-sdk \
    lv2-dev \
    liblilv-dev \
    liblrdf0-dev \
    librtaudio-dev \
    python3-dev
```

---

## 2. Standard CMake Build Workflow

### Using the unified build script (recommended):
```bash
./scripts/build_muse.sh --release --jobs $(nproc)
```

### Dependency Verification:
```bash
./scripts/build_muse.sh --check-deps
```

### Manual CMake commands:
```bash
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DMODULES_BUILD_STATIC=ON \
      ../src
cmake --build . -j$(nproc)
sudo cmake --install .
```

---

## 3. Running MusE

Ensure JACK or PipeWire-JACK is active prior to launching:
```bash
# Launch with real-time JACK backend:
muse4 -a jack

# Launch with ALSA direct backend:
muse4 -a alsa

# View all options:
muse4 --help
```

---

## 4. AppImage Packaging
MusE utilizes `linuxdeploy` and `linuxdeploy-plugin-qt` for portable standalone AppImage creation. See `.github/workflows/` for exact CI AppImage generation recipes.
