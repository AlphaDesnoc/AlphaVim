# Alphavim

> **A blazing-fast, modular, Vim-inspired text editor in pure C.**

---

## ✨ Features
- **Vim-like navigation:** hjkl, arrows, Home/End/PageUp/PageDown
- **Insert & Normal modes:** switch with `i` and `ESC`
- **Dynamic, colored status bar**
- **Interactive command line:** `:q`, `:w`, `:h`, `/search`
- **Syntax highlighting:** C keywords, search highlighting
- **Efficient buffer management:** insert/delete lines/chars
- **File open/save:** prompt for filename if not provided
- **Minimal dependencies:** only standard C and POSIX
- **Optimized for performance and memory**

---

## 🚀 Getting Started

### Build
```sh
make all
```

### Run
```sh
./alphavim [filename]
```
- If `filename` is provided, it is loaded and used for saving.
- If not, you will be prompted for a filename on first save (`:w`).

---

## 🕹️ Controls & Commands

### Navigation
- **Arrow keys** or **hjkl** for movement
- **Home/End/PageUp/PageDown** supported
- **Insert mode:** press `i` to enter, `ESC` to leave

### Commands (type in command line)
- `:q` — Quit
- `:w` — Save
- `:h` — Help
- `/word` — Search (highlights occurrences)

---

## 🗂️ Code Structure
- `src/main.c` — Main loop, input handling
- `src/terminal.c` — Terminal raw mode, key reading, cursor
- `src/buffer.c` — Buffer management
- `src/display.c` — Rendering, status bar, highlighting
- `src/command.c` — Command processing
- `src/file.c` — File I/O
- `src/my_string.c` — String utilities
- `src/ansi_cursor_seq.c` — ANSI cursor sequences
- `includes/alphavim.h` — Central header
- `includes/*.h` — Module headers

---

## 🛠️ Extending Alphavim
- Add new commands in `src/command.c`
- Improve syntax highlighting in `src/display.c`
- Add buffer/file features in `src/buffer.c` and `src/file.c`

---

## 💡 Philosophy
Alphavim is designed for speed, minimalism, and hackability. Every byte counts. No bloat, no dependencies—just pure C and terminal magic.

---

## 📄 License
GNU GENERAL PUBLIC LICENSE
