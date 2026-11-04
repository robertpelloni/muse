# MusE Roadmap

This roadmap establishes the structural evolution and long-term milestones for MusE (Linux Digital Audio Workstation and Sequencer).

---

## Milestone 1: Unified Architecture & Qt6 Modernization
- **Phase 1.1: Complete Qt6 Compatibility**
  - Modernize CMake build system to support both Qt 5.15 LTS and Qt 6.x natively.
  - Audit and refactor deprecated Qt5 widgets, containers, and event handling loops (`QRegExp` -> `QRegularExpression`, `QString::null` removals, high-DPI pixel ratio adaptations).
  - Eliminate strict ECM (Extra CMake Modules) hard dependencies where standard CMake 3.16+ features suffice.
- **Phase 1.2: Modernized Audio & MIDI Engine Core**
  - Decouple engine core from GUI thread structures, providing a clean headless/daemon mode (`mused`).
  - Strengthen real-time thread safety for JACK, ALSA, and PulseAudio/PipeWire backends.
  - Standardize lock-free ring buffers across all audio routing channels and plugin instances.

---

## Milestone 2: UI Redesign & Dashboard Consolidation
- **Phase 2.1: Single-Window Consolidated Workspace**
  - Consolidate fragmented multi-window dialogs (Arranger, Pianoroll, Score, Wave Edit, Mixer, Transport) into a flexible, dockable single-window dashboard layout using Qt Advanced Docking or Qt Quick / modern QDockWidgets.
  - Prioritize high-value workflows:
    1. Primary Track Arranger & Timeline (dominant center view).
    2. Contextual Inspector / Clip Property Panel (left or bottom collapsible dock).
    3. Master Mixer & Channel Strips (dockable lower panel or floating toggle).
    4. Unified Master Transport & Telemetry Bar (persistent top/bottom bar with zero latency indicators).
- **Phase 2.2: Comprehensive UX Tooltips & Guidance**
  - Implement full-coverage descriptive tooltips across all sliders, buttons, dials, routing matrix entries, and transport elements.
  - Introduce contextual "What's This?" (`QWhatsThis`) documentation integrated into interactive controls.

---

## Milestone 3: System Tray Controller & Daemon Management
- **Phase 3.1: MusE System Tray Daemon (`QSystemTrayIcon`)**
  - Integrated persistent System Tray / Notification Area controller for MusE (`QSystemTrayIcon`).
  - Quick action menu from tray:
    - Transport controls: Play / Pause / Record / Rewind to Start.
    - Server status monitor: JACK / PipeWire server status, CPU load, buffer underrun (xrun) count.
    - Emergency Audio Panic: All-notes-off and controls reset.
    - Clean shutdown handler: Safely stop servers, release audio device locks, save state, and terminate background workers.
- **Phase 3.2: Headless & Remote Operation**
  - Support background sequencing and MIDI routing while GUI is minimized to the system tray.
  - Expose OSC (Open Sound Control) and MIDI remote control hooks for hardware control surfaces.

---

## Milestone 4: Next-Generation Plugin Architecture
- **Phase 4.1: Modern Plugin Ecosystem**
  - Robust LV2, VST2, VST3, CLAP, and LADSPA/DSSI hosting.
  - Out-of-process plugin sandboxing to prevent plugin crashes from crashing the sequencer engine.
  - Preset management overhaul with tag-based search and instant auditioning.
