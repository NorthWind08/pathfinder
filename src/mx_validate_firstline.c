#include "../inc/pathfinder.h"

int mx_validate_firstline(char *file) {
    int i = 0;
    
    for (; file[i] != '\n'; i++) {
        if (!mx_isdigit(file[i])) {
            free(file);
            file = NULL;
            mx_print_line_err(0);
        }
    }

    return i;
}
