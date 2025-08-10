/*
 * Buffer module for Alphavim
 *
 * Manages the text buffer: lines, characters, insertion, deletion.
 *
 * Functions:
 *   - buffer_init(): Initializes the buffer.
 *   - buffer_insert_char(int line, int col, char c): Inserts character at position.
 *   - buffer_insert_line(int line): Inserts a new line at position.
 *   - buffer_delete_char(int line, int col): Deletes character at position.
 *   - buffer_get_line(int line): Returns pointer to line.
 *   - buffer_line_length(int line): Returns length of line.
 *   - buffer_line_count(): Returns number of lines in buffer.
 */
#include "../includes/alphavim.h"

static char buf[BUF_LINES][BUF_COLS];
static int line_count = 1;

/*
 * Initializes the buffer to empty lines and resets line count to 1.
 */
void buffer_init() {
    for (int i = 0; i < BUF_LINES; ++i) buf[i][0] = 0;
    line_count = 1;
}

/*
 * Inserts character 'c' at position (line, col) in the buffer.
 * Shifts existing characters to the right if needed.
 * Does nothing if out of bounds.
 */
void buffer_insert_char(int line, int col, char c) {
    if (line < BUF_LINES && col < BUF_COLS-1) {
        int len = 0;
        while (buf[line][len]) ++len;
        if (col <= len) {
            for (int i = len; i >= col; --i) buf[line][i+1] = buf[line][i];
            buf[line][col] = c;
        } else {
            buf[line][len] = c;
            buf[line][len+1] = 0;
        }
    }
}

/*
 * Inserts a new empty line at position 'line'.
 * Shifts lines below down. Does nothing if buffer is full.
 */
void buffer_insert_line(int line) {
    if (line < BUF_LINES-1 && line_count < BUF_LINES) {
        for (int i = line_count; i > line; --i) {
            int j = 0;
            while ((buf[i][j] = buf[i-1][j])) ++j;
        }
        buf[line][0] = 0;
        ++line_count;
    }
}

/*
 * Deletes the character at position (line, col) in the buffer.
 * Shifts remaining characters left.
 */
void buffer_delete_char(int line, int col) {
    int len = 0;
    while (buf[line][len]) ++len;
    if (col < len) {
        for (int i = col; i < len; ++i) buf[line][i] = buf[line][i+1];
    }
}

/*
 * Returns a pointer to the string representing line 'line'.
 */
char *buffer_get_line(int line) { return buf[line]; }

/*
 * Returns the length of line 'line'.
 */
int buffer_line_length(int line) { int l=0; while(buf[line][l])++l; return l; }

/*
 * Returns the current number of lines in the buffer.
 */
int buffer_line_count() { return line_count; }
