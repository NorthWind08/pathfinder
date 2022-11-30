#include "../inc/pathfinder.h"

char **mx_create_link(const char *str) {
    char **tmp1 = mx_strsplit(str, '-');
    char **tmp2 = mx_strsplit(tmp1[1], ',');

    char **link = (char **)malloc(sizeof(char *) * 4);
    link[0] = tmp1[0];
    link[1] = tmp2[0];
    link[2] = tmp2[1];
    link[3] = NULL;
    free(tmp1[1]);

    return link;
}

