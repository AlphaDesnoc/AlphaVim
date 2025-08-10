/*
 * File module for Alphavim
 *
 * Handles file opening and saving.
 *
 * Functions:
 *   - open_file(const char *filename): Loads file content into buffer.
 *   - save_file(const char *filename): Saves buffer content to file.
 */
#include "../includes/alphavim.h"

/*
 * Loads file content into buffer.
 * filename: file to open
 * Returns 0 on success, -1 on error.
 */
int open_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;
    buffer_init();
    char line[BUF_COLS];
    int l = 0;
    while (fgets(line, BUF_COLS, f) && l < BUF_LINES) {
        int i = 0;
        while (line[i] != '\0' && line[i] != '\n') {
            buffer_insert_char(l, i, line[i]);
            i++;
        }
        l++;
    }
    fclose(f);
    return 0;
}

/*
 * Saves buffer content to file.
 * filename: file to write
 * Returns 0 on success, -1 on error.
 */
int save_file(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return -1;
    int lines = buffer_line_count();
    for (int i = 0; i < lines; i++) {
        fputs(buffer_get_line(i), f);
        fputc('\n', f);
    }
    fclose(f);
    return 0;
}
