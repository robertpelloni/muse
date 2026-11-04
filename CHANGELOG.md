# Changelog

All notable changes to MusE are documented in this file. Version numbers track the single source of truth defined in `VERSION.md`.

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
