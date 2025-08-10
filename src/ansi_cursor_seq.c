/*
 * ANSI cursor sequence module for Alphavim
 *
 * Generates ANSI escape sequences for cursor positioning.
 *
 * Functions:
 *   - ansi_cursor_seq(int line, int col, char *out, int out_size):
 *     Generates escape sequence for cursor position.
 */
#include "../includes/alphavim.h"

/*
 * Generates ANSI escape sequence for cursor positioning.
 * line: 1-based line number
 * col:  1-based column number
 * out: output buffer
 * out_size: size of output buffer
 * Returns number of bytes written to 'out'.
 */
int ansi_cursor_seq(int line, int col, char *out, int out_size) {
    int i = 0;
    if (out_size < 7) return 0;
    out[i++] = '\x1b';
    out[i++] = '[';
    int l = line;
    char tmp[6];
    int len = 0;
    if (l == 0) tmp[len++] = '0';
    else {
        int t = l;
        while (t > 0) {
            tmp[len++] = '0' + (t % 10);
            t /= 10;
        }
        for (int j = len - 1; j >= 0; j--) out[i++] = tmp[j];
    }
    out[i++] = ';';
    int c = col;
    len = 0;
    if (c == 0) tmp[len++] = '0';
    else {
        int t = c;
        while (t > 0) {
            tmp[len++] = '0' + (t % 10);
            t /= 10;
        }
        for (int j = len - 1; j >= 0; j--) out[i++] = tmp[j];
    }
    out[i++] = 'H';
    return i;
}
