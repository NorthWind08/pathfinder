#include "../inc/pathfinder.h"

char *mx_validate_file(const char *filename) {

    int fl = open(filename, O_RDONLY);

    if (fl == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(1);
    }

    char *file = mx_file_to_str(filename);

    if (mx_strlen(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        free(file);
        file = NULL;
        exit(1);
    }

    return file;
}

