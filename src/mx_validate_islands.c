#include "../inc/pathfinder.h"

int mx_validate_islands(char **names, int num, char **text,
char ***names_split, char ***nums_split) {

    int len = 1;
    for (; names[len] != NULL; len++);

    t_list *arr = mx_create_names_list(names);

    for (int i = 0; i < len; i += 2) {
        if (mx_strcmp(names[i], names[i + 1]) == 0) {

            mx_strdel(text);
            mx_clear_list(&arr, true);
            mx_del_strarr(nums_split);
            mx_del_strarr(names_split);
            mx_print_line_err(i / 2 + 1);
        }
    }

    for (int i = 0; i < len - 2; i += 2) {
        for (int j = i; j < len - 2; j += 2) {
            if (
                (mx_strcmp(names[i], names[j + 2]) == 0 && 
                mx_strcmp(names[i + 1], names[j + 3]) == 0)
                ||
                (mx_strcmp(names[i], names[j + 3]) == 0 && 
                mx_strcmp(names[i + 1], names[j + 2]) == 0)
            ) {
                mx_strdel(text);
                mx_clear_list(&arr, true);
                mx_del_strarr(nums_split);
                mx_del_strarr(names_split);
                mx_printerr("error: duplicate bridges\n");
                exit(-1);
            }
        }
    }

    int real_length = mx_list_size(arr);
    mx_clear_list(&arr, true);
    return real_length - num;
}

