#include "../inc/pathfinder.h"

void mx_validate_sysargs(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
