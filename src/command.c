/*
 * Command module for Alphavim
 *
 * Handles ex commands (:q, :w, :h, /search), file saving, and user messages.
 *
 * Functions:
 *   - process_command(const char *cmd, char *filename): Processes commands, handles file save and search.
 */
#include "../includes/alphavim.h"

/*
 * Processes ex commands (e.g. :q, :w, :h, /search).
 * cmd: command string
 * filename: current file name (may be updated for :w)
 * Handles file saving, quitting, help, and search.
 * Returns 0 always.
 */
int process_command(const char *cmd, char *filename) {
    if (cmd[0] == 'q') { set_cmd_message(""); write(1, "\x1b[2J", 4); write(1, "\x1b[H", 3); exit(0); }
    if (cmd[0] == 'w') {
        if (filename[0] == '\0') {
            set_cmd_message("Nom du fichier ? :");
            char input[128];
            int n = read(0, input, 127);
            if (n > 0) {
                input[n] = '\0';
                int i = 0;
                while (input[i] && input[i] != '\n' && input[i] != '\r') i++;
                input[i] = '\0';
                my_strncpy(filename, input, 127);
                filename[127] = '\0';
            }
        }
        if (filename[0] != '\0')
            set_cmd_message(save_file(filename)==0?"[Enregistré]":"[Erreur]");
        else
            set_cmd_message("[Erreur: nom de fichier manquant]");
    }
    if (cmd[0] == 'h') { set_cmd_message("Commandes : :q quitter, :w enregistrer, :h aide, /mot recherche"); }
    if (cmd[0] == '/') { set_search_word(cmd+1); set_cmd_message("[Recherche : mot surligné]"); }
    return 0;
}
