# Changelog

All notable changes to MusE are documented in this file. Version numbers track the single source of truth defined in `VERSION.md`.

---

## [4.2.1-autonomous-rev7] - 2025-11-04

### Changed
- **Arranger Toolbar UX Tooltips**:
  - Enriched interactive tooltips in `src/muse/arranger/arranger.cpp` across the main timeline toolbar.
  - Added descriptive tips for playhead cursor position, grid snap toggling, raster division picker, song bar length, global MIDI pitch shift, global tempo scaling, and quick speed multiplier buttons (50%, Normal, 200%).
  - Bumped version to `4.2.1-autonomous-rev7` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev6] - 2025-11-04

### Added
- **Automated Regression Test Suite**:
  - Created `tests/test_song_convert.py` validating CLI flags, error handling, and song XML conversion.
- **Enhanced Song Converter CLI**:
  - In `src/utils/muse-song-convert.py`, added `--help` / `-h` handling and file existence checks with clean exit codes.
  - Bumped version to `4.2.1-autonomous-rev6` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev5] - 2025-11-04

### Changed
- **Mixer Component Rack Tooltips**:
  - Enriched interactive tooltips in `src/muse/mixer/astrip.cpp` for aux send levels (`Aux send level to auxiliary bus (dB)`), volume fader (`Track volume/gain fader (dB)`), pan controls (`Stereo panorama / balance position`), and mute toggles (`Track output mute toggle`).
  - Bumped version to `4.2.1-autonomous-rev5` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev4] - 2025-11-04

### Changed
- **Mixer Channel Strip UX Tooltips**:
  - Enriched interactive tooltips in `src/muse/mixer/astrip.cpp` (audio channel strips) and `src/muse/mixer/mstrip.cpp` (MIDI channel strips).
  - Explicitly clarified Record Arm, Mute (proxy/phantom mute propagation), and Solo monitoring functions.
  - Bumped version to `4.2.1-autonomous-rev4` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev3] - 2025-11-04

### Changed
- **Roadmap Architecture Expansion**:
  - Significantly expanded `ROADMAP.md` covering five comprehensive structural milestones:
    1. Multi-platform headless audio daemon (`mused`) and WebAssembly remote control client.
    2. Single-window consolidated dashboard workspace with Qt Advanced Docking, deep tooltip coverage, and SVG asset vectorization.
    3. IPC out-of-process plugin sandboxing for VST2/VST3/LV2/CLAP to prevent host DAW crashes.
    4. Native direct PipeWire audio driver and adaptive lock-free audio graph scheduler.
    5. Machine-learning studio workflows including Demucs stem splitting, beat transient slicing, and harmonic MIDI generation.
  - Bumped version to `4.2.1-autonomous-rev3` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev2] - 2025-11-04

### Changed
- **CMake Dependency Decoupling**:
  - In `src/CMakeLists.txt`, transformed `find_package(ECM REQUIRED NO_MODULE)` into a non-blocking `find_package(ECM QUIET NO_MODULE)`.
  - Added graceful fallback to bundled `cmake/CheckAtomic.cmake` when Extra CMake Modules (ECM) is not installed, eliminating a hard build barrier on minimal distributions.
  - Bumped version to `4.2.1-autonomous-rev2` in `VERSION.md`.

---

## [4.2.1-autonomous-rev1] - 2025-11-04

### Added
- **Centralized Versioning Standard**: Established `VERSION.md` as the single source of truth for repository build versions.
- **System Tray Controller**:
  - Implemented `QSystemTrayIcon` support in `src/muse/app.h` and `src/muse/app.cpp` via `initSystemTray()`.
  - Added tray context menu with Show/Hide toggle (`toggleWindowVisibility()`), Play/Stop/Record actions, Emergency Audio Panic (`panicStop()`), and Safe Application/Server Quit (`quitDoc()`).
- **Enhanced UI Tooltips**:
  - Added descriptive tooltips and action explanations to transport controls (Play, Stop, Record) to improve workflow transparency.
- **Architectural Documentation Suite**:
  - `VISION.md`: Comprehensive statement of DAW goals, foundational principles, and UX design paradigms.
  - `MEMORY.md`: Detailed engineering map, threading model, and architectural patterns.
  - `DEPLOY.md`: Build requirements, dependency lists, and packaging workflows.
  - `IDEAS.md`: Architectural ideas including headless daemon mode, sandboxed plugins, and unified dashboard layouts.
  - `ROADMAP.md`: Long-term technical milestones for Qt6 migration, consolidated workspace, and system tray controller.
  - `TODO.md`: Immediate actionable engineering tasks and quality assurance checks.
  - `HANDOFF.md`: Comprehensive session state, insights, and transition guide for successor agents.
- **Unified Build Automation**:
  - Introduced `scripts/build_muse.sh` featuring dependency checks, clean builds, parallel jobs, and release/debug targets.
- **Autonomous Tooling**:
  - Created repo analyzer utility `/home/jules/self_created_tools/repo_analyzer.py`.

### Changed
- Preserved and archived legacy build scripts non-destructively under `scripts/archive/`.
- Streamlined repository organization and updated `.gitignore`.
