#ifndef TERMINAL_H
#define TERMINAL_H

void enableRawMode();
void disableRawMode();
void moveCursor(int line, int col);

#endif
