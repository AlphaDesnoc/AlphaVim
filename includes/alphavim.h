/*
 * Alphavim - Minimal Vim-like Editor (Header Documentation)
 *
 * This header centralizes all prototypes and constants for Alphavim modules.
 *
 * USAGE:
 *   #include "alphavim.h"
 *
 * MAIN MODULES:
 *   - Terminal control (raw mode, cursor)
 *   - Buffer management (lines, characters)
 *   - Display (screen rendering, status bar)
 *   - Command processing (ex commands, search)
 *   - File I/O (open, save)
 *   - String utilities (compact replacements)
 *   - ANSI cursor sequence generation
 *
 * CONSTANTS:
 *   BUF_LINES: Maximum number of lines in buffer
 *   BUF_COLS:  Maximum number of columns per line
 *
 * FUNCTION DOCUMENTATION:
 *
 * int ansi_cursor_seq(int line, int col, char *out, int out_size);
 *   Generate ANSI escape sequence for cursor positioning.
 *   Returns the number of bytes written to 'out'.
 *
 * int my_strlen(const char *s);
 *   Returns the length of string 's'.
 * void my_strcpy(char *dest, const char *src);
 *   Copies string 'src' to 'dest'.
 * void my_strncpy(char *dest, const char *src, int n);
 *   Copies up to 'n' characters from 'src' to 'dest'.
 * int my_strcmp(const char *a, const char *b);
 *   Compares two strings, returns 0 if equal.
 * int my_strncmp(const char *a, const char *b, int n);
 *   Compares up to 'n' characters of two strings.
 *
 * void enableRawMode();
 *   Enables raw mode for terminal input.
 * void disableRawMode();
 *   Restores terminal to previous mode.
 * void moveCursor(int line, int col);
 *   Moves cursor to (line, col) using ANSI sequence.
 * int read_key();
 *   Reads a key from stdin, returns code (supports arrows, Home/End/Page).
 *
 * void buffer_init();
 *   Initializes the text buffer.
 * void buffer_insert_char(int line, int col, char c);
 *   Inserts character 'c' at (line, col).
 * void buffer_insert_line(int line);
 *   Inserts a new line at position 'line'.
 * void buffer_delete_char(int line, int col);
 *   Deletes character at (line, col).
 * char *buffer_get_line(int line);
 *   Returns pointer to line 'line'.
 * int buffer_line_length(int line);
 *   Returns length of line 'line'.
 * int buffer_line_count();
 *   Returns current number of lines in buffer.
 *
 * void draw_screen(int cx, int cy, int mode);
 *   Renders the buffer, status bar, and command line.
 *
 * void set_cmd_message(const char *msg);
 *   Sets the message displayed in the command/status bar.
 * void set_search_word(const char *word);
 *   Sets the current search word for highlighting.
 *
 * int process_command(const char *cmd, char *filename);
 *   Processes ex commands (:q, :w, :h, /search), handles file save.
 *
 * int open_file(const char *filename);
 *   Loads file content into buffer.
 * int save_file(const char *filename);
 *   Saves buffer content to file.
 */
#ifndef ALPHAVIM_H
#define ALPHAVIM_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "terminal.h"
#include "buffer.h"
#include "display.h"
#include "command.h"
#include "file.h"
#include <termios.h>


int ansi_cursor_seq(int line, int col, char *out, int out_size);

int my_strlen(const char *s);
void my_strcpy(char *dest, const char *src);
void my_strncpy(char *dest, const char *src, int n);
int my_strcmp(const char *a, const char *b);
int my_strncmp(const char *a, const char *b, int n);

void enableRawMode();
void disableRawMode();
void moveCursor(int line, int col);
int read_key();

#define BUF_LINES 100
#define BUF_COLS 256
void buffer_init();
void buffer_insert_char(int line, int col, char c);
void buffer_insert_line(int line);
void buffer_delete_char(int line, int col);
char *buffer_get_line(int line);
int buffer_line_length(int line);
int buffer_line_count();

void draw_screen(int cx, int cy, int mode);

void set_cmd_message(const char *msg);
void set_search_word(const char *word);

int process_command(const char *cmd, char *filename);

int open_file(const char *filename);
int save_file(const char *filename);

#endif
