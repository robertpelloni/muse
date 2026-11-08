# Changelog

All notable changes to MusE are documented in this file. Version numbers track the single source of truth defined in `VERSION.md`.

---

## [4.2.1-autonomous-rev25] - 2025-11-04

### Changed
- **CheckBox Component UI Guidance**:
  - Added default fallback tooltip to `MusEGui::CheckBox` (`src/muse/widgets/checkbox.cpp`) explaining left-click toggling and right-click options for custom checkboxes.
  - Bumped version to `4.2.1-autonomous-rev25` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev24] - 2025-11-04

### Changed
- **SliderBase / Fader Component UI Guidance**:
  - Added default fallback tooltip to `MusEGui::SliderBase` (`src/muse/widgets/sliderbase.cpp`) explaining click-and-drag adjustment, double-click, and Ctrl+click reset for all slider and fader controls throughout MusE.
  - Bumped version to `4.2.1-autonomous-rev24` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev23] - 2025-11-04

### Changed
- **Rotary Knob Component UI Guidance**:
  - Added default fallback tooltip to `MusEGui::Knob` (`src/muse/widgets/knob.cpp`) explaining drag, mouse wheel, double-click, and Ctrl+click interactions for all rotary controls throughout MusE.
  - Bumped version to `4.2.1-autonomous-rev23` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev22] - 2025-11-04

### Changed
- **Wave Editor Functions Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/waveedit/waveedit.cpp` for core audio manipulation functions: Mute Selection, Normalize Selection, Fade-in Selection, Fade-out Selection, Reverse Selection, and Gain presets (200%, 150%, 75%, 50%, 25%, Other).
  - Bumped version to `4.2.1-autonomous-rev22` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev21] - 2025-11-04

### Changed
- **Wave Editor Edit Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/waveedit/waveedit.cpp` for core audio editing and selection actions: Cut, Copy, Paste, Create Part from Range, Edit in External Editor, Select All, Deselect All, Set Range to Selection, Next Part, and Previous Part.
  - Bumped version to `4.2.1-autonomous-rev21` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev20] - 2025-11-04

### Changed
- **Score Editor Functions Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/midiedit/scoreedit.cpp` for core score transformation functions: Quantize, Change Note Velocity, Crescendo/Decrescendo, Move Notes, Delete Overlaps, Erase Events, Change Note Length, Set Fixed Length, Transpose, and Legato.
  - Bumped version to `4.2.1-autonomous-rev20` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev19] - 2025-11-04

### Changed
- **Score Editor Edit and Select Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/midiedit/scoreedit.cpp` for core score editing and selection actions: Cut, Copy, Copy Events in Range, Paste, Paste (With Dialog), Delete Events, Select All, Deselect All, Invert Selection, Select Inside Loop, and Select Outside Loop.
  - Bumped version to `4.2.1-autonomous-rev19` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev18] - 2025-11-04

### Changed
- **Drum Editor Edit Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/midiedit/drumedit.cpp` for core drum editing actions: Cut (Ctrl+X), Copy (Ctrl+C), Copy in Range, Paste (Ctrl+V), Paste to Current Part, and Delete (Del).
  - Bumped version to `4.2.1-autonomous-rev18` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev17] - 2025-11-04

### Changed
- **Piano Roll Edit Menu UI Guidance**:
  - Enriched interactive tooltips in `src/muse/midiedit/pianoroll.cpp` for core MIDI editing operations: Cut (Ctrl+X), Copy (Ctrl+C), Copy in Range, Paste (Ctrl+V), and Paste to Current Part.
  - Bumped version to `4.2.1-autonomous-rev17` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev16] - 2025-11-04

### Changed
- **Wave Edit Gain Dialog UI Guidance**:
  - Added descriptive tooltip to `sliderGain` in `src/muse/waveedit/editgainbase.ui` clarifying audio clip gain percentage scaling (0% to 200%).
  - Bumped version to `4.2.1-autonomous-rev16` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev15] - 2025-11-04

### Changed
- **PosEdit Component Guidance**:
  - Added helpful default fallback tooltip to `MusEGui::PosEdit` in `src/muse/components/posedit.cpp`, instructing users on mouse wheel and arrow key segment adjustments.
  - Bumped version to `4.2.1-autonomous-rev15` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev14] - 2025-11-04

### Changed
- **Build Runner Test Automation**:
  - Added `-t` / `--test` flag to `scripts/build_muse.sh` to execute the automated Python regression test suite (`tests/`) standalone or post-build.
  - Updated `DEPLOY.md` with instructions for running test suites via the build script.
  - Bumped version to `4.2.1-autonomous-rev14` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev13] - 2025-11-04

### Changed
- **Marker View UI Guidance**:
  - Enriched interactive tooltips in `src/muse/marker/markerview.cpp` for adding markers (A), deleting markers, the marker list table, musical beat edit controls, SMPTE timecode editing, SMPTE lock toggle, and description field.
  - Bumped version to `4.2.1-autonomous-rev13` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev12] - 2025-11-04

### Changed
- **Master Editor Toolbar UI Guidance**:
  - Enriched interactive tooltips in `src/muse/master/masteredit.cpp` across the master tempo/time info toolbar.
  - Added descriptive tips for playhead cursor position (Bar:Beat:Tick), tempo indicator (BPM), master grid snap toggling, and quantize raster division picker.
  - Bumped version to `4.2.1-autonomous-rev12` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev11] - 2025-11-04

### Changed
- **Clip List Editor UI Guidance**:
  - Enriched interactive tooltips in `src/muse/cliplist/cliplisteditorbase.ui` for the audio clip tree view, clip start offset (`SMPTE time`), and clip playback duration length (`SMPTE time`).
  - Bumped version to `4.2.1-autonomous-rev11` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev10] - 2025-11-04

### Changed
- **CMake Modernization**:
  - Replaced obsolete `EXEC_PROGRAM` calls in `src/CMakeLists.txt` with modern `execute_process(...)` for Git metadata extraction.
  - Eliminated CMake policy CMP0153 deprecation warnings.
  - Bumped version to `4.2.1-autonomous-rev10` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev9] - 2025-11-04

### Added
- **Unused WAV Cleaner Modernization & Testing**:
  - Upgraded `src/utils/muse-find-unused-wavs` to Python 3 with `argparse`, supporting `--dry-run`, non-interactive execution (`-y` / `--yes`), and custom target directories (`-d` / `--dir`).
  - Added unit test suite `tests/test_find_unused_wavs.py` verifying CLI handling, dry-run scanning, and automated file relocation.
  - Bumped version to `4.2.1-autonomous-rev9` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

---

## [4.2.1-autonomous-rev8] - 2025-11-04

### Changed
- **Arranger View Edit Action Tooltips**:
  - Enriched interactive tooltips in `src/muse/arranger/arrangerview.cpp` for core editing operations: Delete, Cut, Copy, Copy in Range, Paste, Paste Clone, Delete Selected Track, and Duplicate Selected Track.
  - Bumped version to `4.2.1-autonomous-rev8` in `VERSION.md`.
  - Updated `TODO.md` and `HANDOFF.md`.

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
