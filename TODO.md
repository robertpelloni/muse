# MusE Actionable Task List (TODO.md)

Granular immediate tasks, bug fixes, and targeted quality-of-life enhancements.

---

## 1. Build System & Tooling Enhancements
- [x] **Optionalize ECM Dependency**: In `src/CMakeLists.txt`, made `ECM` optional (`find_package(ECM QUIET NO_MODULE)`) with graceful fallback to local CMake modules (`CheckAtomic.cmake`), allowing minimal Linux systems to configure CMake without `extra-cmake-modules`.
- [x] **Unified Multi-target Build Script**: Created and verified `scripts/build_muse.sh` with interactive flags (`--release`, `--debug`, `--check-deps`, `--clean`, `--jobs`, `--test`) alongside non-destructively archived legacy scripts in `scripts/archive/`.
- [x] **Modernize CMake Executables & Policy CMP0153**: Replaced obsolete `EXEC_PROGRAM` with `execute_process` for Git metadata extraction in `src/CMakeLists.txt`.
- [x] **Automated Regression Testing**: Created unit test suite in `tests/test_song_convert.py` verifying headless XML conversion and CLI reliability.
- [x] **Automated Audio Asset Cleanup Testing**: Created unit test suite in `tests/test_find_unused_wavs.py` verifying non-interactive asset cleanup and dry-run reporting.
- [x] **Modernize Compiler Flags**: Audited C++17 compliance flags (`CMAKE_CXX_STANDARD 17`, `CMAKE_CXX_STANDARD_REQUIRED ON`, `CMAKE_CXX_EXTENSIONS OFF`) and verified warning flags (`-Werror=format-security -Wextra -Wall -fPIC -fexceptions`) across all build types in `src/CMakeLists.txt`.

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
  - [x] Enriched clip list editor tooltips in `cliplisteditorbase.ui` (clip tree view, clip start offset, clip duration length).
  - [x] Enriched master editor tooltips in `masteredit.cpp` (cursor position, tempo label, grid snap button, raster division picker).
  - [x] Enriched marker view tooltips in `markerview.cpp` (add marker, delete marker, marker table, measure edit, SMPTE edit, timecode lock toggle, description edit).
  - [x] Enriched PosEdit timeline widget fallback tooltip in `posedit.cpp` with wheel/key navigation instructions.
  - [x] Enriched wave edit gain dialog tooltip in `editgainbase.ui` for clip gain scaling.
  - [x] Enriched piano roll editor edit menu tooltips in `pianoroll.cpp` (Cut, Copy, Copy in Range, Paste, Paste to Current Part).
  - [x] Enriched drum editor edit menu tooltips in `drumedit.cpp` (Cut, Copy, Copy in Range, Paste, Paste to Current Part, Delete).
  - [x] Enriched score editor edit and select menu tooltips in `scoreedit.cpp` (Cut, Copy, Copy in Range, Paste, Paste Dialog, Delete Events, Select All, Deselect All, Invert Selection, Select Inside Loop, Select Outside Loop).
  - [x] Enriched score editor functions menu tooltips in `scoreedit.cpp` (Quantize, Note Velocity, Crescendo, Move Notes, Delete Overlaps, Erase Events, Note Length, Fixed Length, Transpose, Legato).
  - [x] Enriched wave editor edit menu tooltips in `waveedit.cpp` (Cut, Copy, Paste, Create Part from Range, Edit in External Editor, Select All, Deselect All, Set Range to Selection, Next Part, Previous Part).
  - [x] Enriched wave editor functions menu tooltips in `waveedit.cpp` (Mute Selection, Normalize, Fade-in, Fade-out, Reverse, Gain presets).
  - [x] Enriched Knob rotary component fallback tooltip in `widgets/knob.cpp` (drag, mouse wheel, double-click, and Ctrl+click interaction guide).
  - [x] Enriched SliderBase component fallback tooltip in `widgets/sliderbase.cpp` (drag, double-click, and Ctrl+click reset guide).
  - [x] Enriched CheckBox component fallback tooltip in `widgets/checkbox.cpp` (click toggle and right-click menu guide).
  - [x] Enriched LineEdit component fallback tooltip in `widgets/line_edit.cpp` (Enter to commit and Escape to cancel guide).
  - [x] Enriched SpinBox component fallback tooltip in `widgets/spinbox.cpp` (arrow buttons, scroll wheel, and Enter confirmation).
  - [x] Enriched CtrlPanel automation lane tooltips in `ctrl/ctrlpanel.cpp` (controller selector and lane remove buttons).
  - [x] Enriched ComboBoxPI component fallback tooltip in `widgets/comboboxpi.cpp` (select option and right-click context menu guide).
  - [x] Enriched ClipperLabel component fallback tooltip in `widgets/clipper_label.cpp` (peak level and clip reset guide).
  - [x] Enriched Meter audio level component fallback tooltip in `widgets/meter.cpp` (level and peak meter guide).
  - [x] Enriched BigTime real-time display and format toggle tooltips in `components/bigtime.cpp`.
- [ ] **Workspace Layout Consolidation**:
  - [ ] Reduce dialog fragmentation by converting standalone utility dialogs into integrated dockable views as planned in `ROADMAP.md` Milestone 2.
  - [ ] Provide default "Compact Dashboard" view grouping arranger, track inspector, and master transport into a single view.

## 3. Engine & Driver Stability
- [ ] **PipeWire Native Backend**: Implement direct PipeWire SPA driver as specified in `ROADMAP.md` Milestone 4 (added `PIPEWIRE_AUDIO=3` to `AudioDevice` enum in `src/muse/driver/audiodev.h`).
- [ ] **Plugin Sandboxing Host**: Develop IPC shared-memory plugin runner to isolate third-party VST/LV2 plugins (`ROADMAP.md` Milestone 3).
- [x] **XRun Logging & Telemetry**: Enriched CPU toolbar and status bar indicators counting audio underruns (xruns) and DSP/CPU load with reset actions and diagnostics (`src/muse/components/cpu_toolbar.cpp`).

## 4. Documentation & Autonomous Governance
- [x] Maintain synchronized single source of truth for versions in `VERSION.md`.
- [x] Keep `CHANGELOG.md` updated with every minor and major release iteration.
- [x] Maintain `MEMORY.md`, `DEPLOY.md`, `VISION.md`, and `IDEAS.md` reflecting all architectural decisions.
- [x] Comprehensive expansion of `ROADMAP.md` across 5 core long-term structural milestones.
