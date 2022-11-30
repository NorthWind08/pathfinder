#include "../inc/pathfinder.h"

void print_route(t_list *names, int *path) {
    int j = 0;
    
    for (; path[j + 1] != -1; j++) {
        mx_printstr(mx_get_by_index(names, path[j]));
        mx_printstr(" -> ");
    }

    mx_printstr(mx_get_by_index(names, path[j]));
}

