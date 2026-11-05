# MusE Actionable Task List (TODO.md)

Granular immediate tasks, bug fixes, and targeted quality-of-life enhancements.

---

## 1. Build System & Tooling Enhancements
- [x] **Optionalize ECM Dependency**: In `src/CMakeLists.txt`, made `ECM` optional (`find_package(ECM QUIET NO_MODULE)`) with graceful fallback to local CMake modules (`CheckAtomic.cmake`), allowing minimal Linux systems to configure CMake without `extra-cmake-modules`.
- [x] **Unified Multi-target Build Script**: Created and verified `scripts/build_muse.sh` with interactive flags (`--release`, `--debug`, `--check-deps`, `--clean`, `--jobs`) alongside non-destructively archived legacy scripts in `scripts/archive/`.
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
  - [ ] Add tooltips across all mixer fader controls, pan pots, mute/solo buttons, and aux sends.
- [ ] **Workspace Layout Consolidation**:
  - [ ] Reduce dialog fragmentation by converting standalone utility dialogs into integrated dockable views.
  - [ ] Provide default "Compact Dashboard" view grouping arranger, track inspector, and master transport into a single view.

## 3. Engine & Driver Stability
- [ ] **PipeWire / JACK Hot-swapping**: Verify graceful reconnection when audio drivers or PipeWire-JACK sessions restart.
- [ ] **ALSA / RtAudio Fallbacks**: Ensure robust error messages when audio devices are claimed exclusively by other processes.
- [ ] **XRun Logging & Telemetry**: Provide a non-intrusive status bar indicator counting audio underruns with clickable diagnostics.

## 4. Documentation & Autonomous Governance
- [x] Maintain synchronized single source of truth for versions in `VERSION.md`.
- [x] Keep `CHANGELOG.md` updated with every minor and major release iteration.
- [x] Maintain `MEMORY.md`, `DEPLOY.md`, `VISION.md`, and `IDEAS.md` reflecting all architectural decisions.
