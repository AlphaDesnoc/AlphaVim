/*
 * Display module for Alphavim
 *
 * Handles screen rendering, status bar, command line, syntax highlighting, and search highlighting.
 *
 * Functions:
 *   - draw_screen(int cx, int cy, int mode): Renders buffer, status bar, and command line.
 *   - set_cmd_message(const char *msg): Sets the message in the status/command bar.
 *   - set_search_word(const char *word): Sets the current search word for highlighting.
 *   - write_colored_line(const char *line): Renders a line with syntax and search highlighting.
 */
#include "../includes/alphavim.h"

#define VIEWPORT_HEIGHT 20
static int scroll = 0;
static char cmd_message[128] = "";
static char search_word[32];

/*
 * Renders the buffer, status bar, and command line to the terminal.
 * cx: cursor column
 * cy: cursor line
 * mode: 0 for normal, 1 for insert
 */
void draw_screen(int cx, int cy, int mode) {
    if (cy < scroll) scroll = cy;
    if (cy >= scroll + VIEWPORT_HEIGHT) scroll = cy - VIEWPORT_HEIGHT + 1;

    write(1, "\x1b[2J", 4);
    write(1, "\x1b[H", 3);
    int lines = buffer_line_count();
    for (int i = scroll; i < lines && i < scroll + VIEWPORT_HEIGHT; ++i) {
        write_colored_line(buffer_get_line(i));
        write(1, "\n", 1);
    }
    if (mode == 0)
        write(1, "\x1b[7m-- NORMAL --\x1b[0m  ", 22);
    else
        write(1, "\x1b[7m-- INSERT --\x1b[0m  ", 22);
    char pos[32];
    int n = snprintf(pos, sizeof(pos), "Ln %d, Col %d", cy+1, cx+1);
    write(1, pos, n);
    write(1, "\n", 1);
    write(1, ":", 1);
    write(1, cmd_message, my_strlen(cmd_message));
    write(1, "\n", 1);
    moveCursor(cy-scroll+1, cx+1);
}

/*
 * Sets the message displayed in the command/status bar.
 */
void set_cmd_message(const char *msg) {
    int i = 0;
    while (msg[i] && i < 127) { cmd_message[i] = msg[i]; i++; }
    cmd_message[i] = '\0';
}

/*
 * Sets the current search word for highlighting in the buffer.
 */
void set_search_word(const char *word) {
    int i = 0;
    while (word[i] && i < 31) { search_word[i] = word[i]; i++; }
    search_word[i] = '\0';
}

/*
 * Renders a line with syntax highlighting and search highlighting.
 * line: string to render
 */
void write_colored_line(const char *line) {
    int i = 0;
    while (line[i] != '\0') {
        if ((i == 0 || line[i-1] == ' ' || line[i-1] == '\t') &&
            (line[i] == 'i' && line[i+1] == 'n' && line[i+2] == 't' && (line[i+3] == ' ' || line[i+3] == '\0' || line[i+3] == '('))) {
            write(1, "\x1b[34mint\x1b[0m", 10); i += 3; continue;
        }
        if ((i == 0 || line[i-1] == ' ' || line[i-1] == '\t') &&
            (line[i] == 'c' && line[i+1] == 'h' && line[i+2] == 'a' && line[i+3] == 'r' && (line[i+4] == ' ' || line[i+4] == '\0' || line[i+4] == '('))) {
            write(1, "\x1b[32mchar\x1b[0m", 11); i += 4; continue;
        }

        int swlen = my_strlen(search_word);
        if (swlen > 0) {
            int match = 1;
            for (int k = 0; k < swlen; k++) {
                if (line[i+k] != search_word[k]) { match = 0; break; }
            }
            if (match) {
                write(1, "\x1b[41m", 5);
                write(1, search_word, swlen);
                write(1, "\x1b[0m", 4);
                i += swlen;
                continue;
            }
        }
        write(1, &line[i], 1);
        i++;
    }
}
