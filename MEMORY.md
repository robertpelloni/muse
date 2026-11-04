# MusE Architecture & Memory Guide (MEMORY.md)

This internal memory guide records the architectural patterns, codebase traits, threading models, and conventions observed across MusE.

---

## 1. Directory Structure & Codebase Map
- `src/muse/`: Core sequencer application code, UI widgets, audio engine, sequencer loop, and track models.
  - `main.cpp`: Process entry point, command-line parsing, Qt application bootstrap, splash screen, and main event loop.
  - `app.cpp`: Main window implementation (`class MusE`), top-level menu bars, workspace layouts, action dispatchers, system tray icon controller (`initSystemTray()`).
  - `audiodev.cpp`, `jackaudio.cpp`, `alsaaudio.cpp`: Audio driver abstraction layers.
  - `midi.cpp`, `mididev.cpp`: Low-level ALSA / JACK MIDI I/O.
  - `song.cpp`: Central project container (`class Song`), tracks list, tempo map, markers, and audio graph.
  - `arranger/`: Timeline arranger view, track canvas, parts visualization, drag-and-drop event handlers.
  - `mixer/`: Audio and MIDI mixer strips, master bussing, fader automation, volume VU meters.
  - `widgets/`: Custom Qt widgets (knobs, sliders, peak meters, time displays).
- `src/synti/`: Built-in synthesizer plugins:
  - `fluidsynth/`: SoundFont2 (.sf2) sample playback synth engine.
  - `organ/`: Tone-wheel additive organ synthesizer.
  - `vam/`: Virtual analog synthesizer.
  - `simpledrums2/`: Multi-sample drum module.
  - `deicsonze/`: FM synthesizer.
- `src/libs/`: Shared utility libraries:
  - `al/`: Audio abstraction primitives, ring buffers, sample rate converters.
  - `awl/`: Audio Widget Library (specialized Qt widgets for audio controls).
- `src/share/`: System resources:
  - `instruments/`: Instrument definition XML files (`.idf`) for MIDI hardware.
  - `templates/`: Project templates for rapid session initialization.
  - `wallpapers/`, `locale/`: UI visuals and translations.
- `muse2/`: Historical branch archive preserved for reference.

---

## 2. Audio Engine & Threading Architecture
- **Dual-Thread Model**:
  - **Real-Time Audio Thread**: Executes the real-time process callback (`JackAudioDevice::process` or ALSA audio pump). Must NEVER allocate memory dynamically, acquire mutexes that can block, perform I/O, or invoke Qt GUI functions.
  - **Sequencer/Heartbeat Thread**: Schedules MIDI events, processes tempo changes, handles automation ramps, and queues audio buffers into lock-free FIFOs.
  - **GUI / Main Thread**: Qt event loop handling user input, canvas repainting, and window state.
- **Inter-Thread Communication**:
  - Circular lock-free ringbuffers (`RingBuffer` in `src/al/`) connect real-time audio threads and GUI worker threads.
  - Sequencer messaging via asynchronous message queues (`seqmsg.cpp`).

---

## 3. UI Conventions & Best Practices
- Every interactive control (knob, fader, button, combo) must define a user-readable `<property name="toolTip">` in its `.ui` definition or explicitly via `setToolTip()`.
- System Tray Integration: `MusE::initSystemTray()` provides background management, window minimization/restoration, quick transport controls, panic all-notes-off reset, and clean server termination.
- Layouts must be stretchable and DPI-aware (`devicePixelRatio`).
