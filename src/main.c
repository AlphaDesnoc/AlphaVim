#include "../includes/alphavim.h"

int cx = 0, cy = 0;
int mode = 0;
char current_filename[128] = "";
void processKeypress() {
    int c = read_key();
    if (mode == 0) {
        if (c == 'i') mode = 1;
        else if (c == 'h' && cx > 0) cx--;
        else if (c == 'l' && cx < buffer_line_length(cy)) cx++;
        else if (c == 'j' && cy < buffer_line_count()-1) cy++;
        else if (c == 'k' && cy > 0) cy--;
        else if (c == 1000 && cy > 0) cy--;
        else if (c == 1001 && cy < buffer_line_count()-1) cy++;
        else if (c == 1002 && cx < buffer_line_length(cy)) cx++;
        else if (c == 1003 && cx > 0) cx--;
        else if (c == ':') {
            char cmd[32];
            int n = read(0, cmd, 31);
            cmd[n] = '\0';
            process_command(cmd, current_filename);
        }
    } else {
        if (c == 27) mode = 0;
        else if (c == '\n') {
            buffer_insert_line(cy);
            cy++;
            cx = 0;
        } else if (c == 127) {
            if (cx > 0) {
                buffer_delete_char(cy, cx-1);
                cx--;
            }
        } else {
            buffer_insert_char(cy, cx, c);
            cx++;
        }
    }
}

int main(int argc, char *argv[]) {
    enableRawMode();
    buffer_init();
    if (argc > 1) {
        my_strncpy(current_filename, argv[1], sizeof(current_filename)-1);
        current_filename[sizeof(current_filename)-1] = '\0';
        open_file(current_filename);
    } else {
        current_filename[0] = '\0';
    }
    while (1) {
        draw_screen(cx, cy, mode);
        processKeypress();
    }
    return 0;
}