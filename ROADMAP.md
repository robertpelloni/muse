# MusE Long-Term Architecture & Engineering Roadmap

This comprehensive roadmap outlines the structural evolution, technical milestones, and user-experience transformations planned for **MusE** (Linux Digital Audio Workstation and Sequencer).

---

## Milestone 1: Multi-Platform Headless Engine & Remote Client Architecture (`mused`)
- **Phase 1.1: Core Audio / Sequencer Decoupling**
  - Architect a clean separation between the sequencer data model (`Song`, `Track`, `Part`, `Event`), the real-time audio/MIDI DSP engine, and the Qt graphical user interface.
  - Create `mused`: a lightweight, high-performance headless sequencer daemon capable of running as a systemd service or on embedded studio appliances (e.g. Raspberry Pi, studio rack units).
  - Provide a standardized C++ asynchronous API and lock-free message bus for external frontend clients.
- **Phase 1.2: Remote Control Bus & WebAssembly Frontend**
  - Implement OSC (Open Sound Control) and WebSocket remote bridges.
  - Build a lightweight HTML5/WebAssembly web client providing remote fader mixing, transport triggering, and real-time metering on tablet and mobile browser screens.
  - Enable multi-user collaborative studio sessions where multiple performers monitor and tweak independent sub-mixes on local Wi-Fi.

---

## Milestone 2: Single-Window Consolidated Workspace & Modern UI Overhaul
- **Phase 2.1: Dockable Modern Dashboard (Qt Advanced Docking)**
  - Transition away from legacy MDI window clutter into a fluid, responsive single-window dashboard.
  - **Upper Center**: Primary Arranger timeline with track canvas, markers, loop bounds, and automation lanes.
  - **Lower Deck**: Context-sensitive tabbed/split panel hosting the Piano Roll (Matrix), Waveform Editor, Audio Mixer, or Plugin Rack depending on active track focus.
  - **Left Sidebar**: Collapsible Track Inspector and File/Preset Browser.
  - **Persistent Header/Footer**: Master Transport, tempo controls, punch in/out, DSP load telemetry, and xrun counter.
- **Phase 2.2: Deep Tooltip Coverage & Contextual Guidance**
  - Guarantee 100% tooltip coverage across all dials, buttons, sliders, routing matrices, and audio bus selectors.
  - Integrate interactive contextual guidance (`QWhatsThis`) with keyboard shortcut displays and signal flow diagrams.
- **Phase 2.3: Modern Theme Engine & High-DPI Polish**
  - Revamp Qt stylesheets (`src/qss/`) with modern flat dark and high-contrast themes.
  - Full vectorization of all legacy XPM icons to high-resolution SVG assets with native support for multi-monitor fractional display scaling.

---

## Milestone 3: Next-Generation Plugin Architecture & Process Sandboxing
- **Phase 3.1: IPC Out-of-Process Plugin Sandboxing**
  - Isolate external VST2, VST3, LV2, and CLAP plugin instances in sandboxed worker sub-processes using shared-memory audio buffers.
  - A crash or memory corruption in a buggy third-party plugin will never crash the host MusE sequencer; the UI displays a non-destructive "Plugin Crashed - Click to Reload" prompt.
- **Phase 3.2: Universal Format Support (CLAP & VST3 Native)**
  - Implement native CLAP (Clever Audio Plugin) hosting with per-note automation and non-destructive parameter modulation.
  - Overhaul VST3 hosting layer with dynamic bus configuration and state serialization.
- **Phase 3.3: Preset Management & Instant Audition**
  - Unified tag-based search database for instrument presets, SoundFonts, and synth patches with real-time audio preview.

---

## Milestone 4: Audio Backend Modernization & Zero-Latency Routing
- **Phase 4.1: Direct PipeWire-Native Driver Integration**
  - Provide a native PipeWire SPA/libpipewire client backend alongside JACK and ALSA, enabling zero-configuration studio operation on modern Linux distros (Fedora, Arch, Ubuntu).
  - Seamless audio device hot-plugging without restarting the sequencer session.
- **Phase 4.2: Lock-Free Audio Graph Engine**
  - Implement an adaptive lock-free dependency audio graph scheduler with multi-core load balancing for extreme track counts.
  - Zero-latency software monitoring with automatic PDC (Plugin Delay Compensation) visualization.

---

## Milestone 5: Intelligent Studio Workflow & Machine Learning Assistance
- **Phase 5.1: Native Audio Stem Separation**
  - Integrate local ONNX/Demucs model execution for instant, non-destructive stem splitting (Vocals, Drums, Bass, Other) directly inside the timeline.
- **Phase 5.2: Transient Detection & Slicing**
  - Intelligent beat transient markers with one-click slice-to-MIDI capabilities routed to SimpleDrums or FluidSynth.
- **Phase 5.3: Harmonic MIDI Assistant**
  - Scale-aware note snapping, chord progression generator, and polyphonic voice leading helpers in the Piano Roll.
