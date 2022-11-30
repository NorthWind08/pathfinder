#include "../inc/pathfinder.h"

void print_path(t_list *names, int *path, int last) {
    mx_printstr(mx_get_by_index(names, path[0]));
    mx_printstr(" -> ");
    mx_printstr(mx_get_by_index(names, path[last]));
}

