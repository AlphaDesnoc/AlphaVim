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
gcc *.c -o alphavim
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
- `main.c` — Main loop, input handling
- `terminal.c` — Terminal raw mode, key reading, cursor
- `buffer.c` — Buffer management
- `display.c` — Rendering, status bar, highlighting
- `command.c` — Command processing
- `file.c` — File I/O
- `my_string.c` — String utilities
- `ansi_cursor_seq.c` — ANSI cursor sequences
- `alphavim.h` — Central header

---

## 🛠️ Extending Alphavim
- Add new commands in `command.c`
- Improve syntax highlighting in `display.c`
- Add buffer/file features in `buffer.c` and `file.c`

---

## 💡 Philosophy
Alphavim is designed for speed, minimalism, and hackability. Every byte counts. No bloat, no dependencies—just pure C and terminal magic.

---

## 📄 License
MIT
