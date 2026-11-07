# MusE Actionable Task List (TODO.md)

Granular immediate tasks, bug fixes, and targeted quality-of-life enhancements.

---

## 1. Build System & Tooling Enhancements
- [x] **Optionalize ECM Dependency**: In `src/CMakeLists.txt`, made `ECM` optional (`find_package(ECM QUIET NO_MODULE)`) with graceful fallback to local CMake modules (`CheckAtomic.cmake`), allowing minimal Linux systems to configure CMake without `extra-cmake-modules`.
- [x] **Unified Multi-target Build Script**: Created and verified `scripts/build_muse.sh` with interactive flags (`--release`, `--debug`, `--check-deps`, `--clean`, `--jobs`) alongside non-destructively archived legacy scripts in `scripts/archive/`.
- [x] **Modernize CMake Executables & Policy CMP0153**: Replaced obsolete `EXEC_PROGRAM` with `execute_process` for Git metadata extraction in `src/CMakeLists.txt`.
- [x] **Automated Regression Testing**: Created unit test suite in `tests/test_song_convert.py` verifying headless XML conversion and CLI reliability.
- [x] **Automated Audio Asset Cleanup Testing**: Created unit test suite in `tests/test_find_unused_wavs.py` verifying non-interactive asset cleanup and dry-run reporting.
- [ ] **Modernize Compiler Flags**: Audit C++17 compliance flags and warnings across all subdirectories (`src/muse`, `src/synti`, `src/libs`).

## 2. Dashboard & GUI Consolidation
- [x] **System Tray Integration**:
  - [x] Added `QSystemTrayIcon` support in `src/muse/app.h` and `src/muse/app.cpp` (`initSystemTray()`).
  - [x] Implemented tray context menu with:
    - Transport controls: Play / Pause / Stop / Record.
    - Window visibility toggle: Show/Hide main window (`toggleWindowVisibility()`).
    - Emergency Audio Engine Reset / Panic button (`panicStop()`).
    - Quit MusE and safely disconnect audio servers (`quitDoc()`).
- [x] **UI Tooltips & Guidance Audit**:
  - [x] Enriched transport tooltips for Play, Stop, and Record actions with clear keyboard shortcuts and workflow descriptions.
  - [x] Enriched mixer channel strip tooltips in `astrip.cpp` and `mstrip.cpp` for Record Arm, Mute (proxy mute explanation), Solo, Volume faders, Pan pots, and Aux send knobs.
  - [x] Enriched arranger timeline toolbar tooltips in `arranger.cpp` (playhead position, snap grid, raster division, song length, pitch shift, tempo scaling and speed multipliers).
  - [x] Enriched arranger view edit action tooltips in `arrangerview.cpp` (Delete, Cut, Copy, Copy in Range, Paste, Paste Clone, Delete Selected Track, Duplicate Selected Track).
- [ ] **Workspace Layout Consolidation**:
  - [ ] Reduce dialog fragmentation by converting standalone utility dialogs into integrated dockable views as planned in `ROADMAP.md` Milestone 2.
  - [ ] Provide default "Compact Dashboard" view grouping arranger, track inspector, and master transport into a single view.

## 3. Engine & Driver Stability
- [ ] **PipeWire Native Backend**: Implement direct PipeWire SPA driver as specified in `ROADMAP.md` Milestone 4.
- [ ] **Plugin Sandboxing Host**: Develop IPC shared-memory plugin runner to isolate third-party VST/LV2 plugins (`ROADMAP.md` Milestone 3).
- [ ] **XRun Logging & Telemetry**: Provide a non-intrusive status bar indicator counting audio underruns with clickable diagnostics.

## 4. Documentation & Autonomous Governance
- [x] Maintain synchronized single source of truth for versions in `VERSION.md`.
- [x] Keep `CHANGELOG.md` updated with every minor and major release iteration.
- [x] Maintain `MEMORY.md`, `DEPLOY.md`, `VISION.md`, and `IDEAS.md` reflecting all architectural decisions.
- [x] Comprehensive expansion of `ROADMAP.md` across 5 core long-term structural milestones.
