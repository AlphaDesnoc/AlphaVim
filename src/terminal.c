/*
 * Terminal module for Alphavim
 *
 * Handles terminal raw mode, cursor movement, and key reading.
 *
 * Functions:
 *   - enableRawMode(): Enables raw input mode for the terminal.
 *   - disableRawMode(): Restores terminal to previous mode.
 *   - moveCursor(int line, int col): Moves the cursor to (line, col) using ANSI escape codes.
 *   - read_key(): Reads a key from stdin, returns code (supports arrows, Home/End/Page).
 */
#include "../includes/alphavim.h"

static struct termios orig_termios;

/*
 * Restores the terminal to its original mode (re-enables echo, canonical mode, signals).
 * Automatically called on exit.
 */
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/*
 * Enables raw input mode for the terminal (disables echo, canonical mode, signals).
 * Should be called before reading keys directly from stdin.
 */
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    raw.c_iflag &= ~(IXON | ICRNL);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/*
 * Moves the cursor to the specified line and column using ANSI escape codes.
 * line: 1-based line number
 * col:  1-based column number
 */
void moveCursor(int line, int col) {
    char seq[16];
    int n = ansi_cursor_seq(line, col, seq, sizeof(seq));
    write(1, seq, n);
}

/*
 * Reads a key from stdin in raw mode.
 * Returns:
 *   - ASCII value for normal keys
 *   - 1000+ for arrow keys (Up/Down/Right/Left)
 *   - 1010+ for Home/End/PageUp/PageDown
 *   - 27 for Escape
 *   - -1 for error
 */
int read_key() {
    char c;
    if (read(0, &c, 1) != 1) return -1;
    if (c == 27) {
        char seq[4];
        if (read(0, seq, 3) != 3) return 27;
        if (seq[0] == '[') {
            if (seq[1] >= 'A' && seq[1] <= 'D') return 1000 + (seq[1] - 'A');
            if (seq[1] >= '1' && seq[1] <= '6' && seq[2] == '~') return 1010 + (seq[1] - '1');
        }
        return 27;
    }
    return c;
}
