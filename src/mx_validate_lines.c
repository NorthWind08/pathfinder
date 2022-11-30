#include "../inc/pathfinder.h"

int mx_validate_lines(char *file) {
    int line = 1;
    int start = mx_validate_firstline(file);
    
    for (int i = start + 1; file[i]; i++) {
        if (file[i] == '\n') {
            line++;
        }

        if ((
                file[i] != '\n' && !mx_isalpha(file[i])
                && !mx_isdigit(file[i]) && file[i] != '-' && file[i] != ','
            ) || (
                file[i] == '\n' && (!mx_isalpha(file[i + 1])
                && file[i + 1] != '\0')
            ) || (
                file[i] == '-' && !mx_isalpha(file[i + 1])
            ) || (
                file[i] == ',' && !mx_isdigit(file[i + 1])
            ) || (
                mx_isalpha(file[i]) && (!mx_isalpha(file[i + 1])
                && file[i + 1] != '-' && file[i + 1] != ',')
            ) || (
                mx_isdigit(file[i]) && (!mx_isdigit(file[i + 1])
                && file[i + 1] != '\n')
            )
        ) {
            free(file);
            file = NULL;
            mx_print_line_err(line);
        }
    }
    
    return line;
}
