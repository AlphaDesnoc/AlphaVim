#ifndef BUFFER_H
#define BUFFER_H

#define BUF_LINES 100
#define BUF_COLS 256

void buffer_init();
void buffer_insert_char(int line, int col, char c);
void buffer_insert_line(int line);
void buffer_delete_char(int line, int col);
char *buffer_get_line(int line);
int buffer_line_length(int line);
int buffer_line_count();

#endif
