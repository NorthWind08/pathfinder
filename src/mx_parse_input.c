#include "../inc/pathfinder.h"

t_list *mx_parse_input(const char *filename, int *islands, int ***paths) {

    char *text = mx_validate_file(filename);
    int size = mx_validate_lines(text);

    char **strarr = mx_strsplit(text, '\n');
    *islands = mx_atoi(strarr[0]);

    char **nums_split = NULL;
    char **names_split = NULL;

    nums_split = (char **)malloc(sizeof(char *) * size);
    names_split = (char **)malloc(sizeof(char *) * (size * 2 - 1));

    char **link = NULL;

    for (int i = 0; i < size - 1; i++) {
        link = mx_create_link(strarr[i + 1]);

        nums_split[i] = link[2];
        names_split[i * 2] = link[0];
        names_split[i * 2 + 1] = link[1];

        free(link);
        link = NULL;
    }


    nums_split[size] = NULL;
    names_split[size * 2 - 1] = NULL;    

    mx_validate_weights(nums_split);

    if (
        mx_validate_islands(
        names_split, *islands, &text, &names_split, &nums_split
    ) != 0) {

        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&nums_split);
        for (int i = 0; i < size * 2; i++) {
            free(names_split[i]);
        }
        mx_del_strarr(&strarr);
        mx_strdel(&text);
        exit(1);
    }

    t_list *unique_islands = mx_create_names_list(names_split);
    *paths = mx_create_paths_matrix(unique_islands, strarr, size, *islands);

    mx_del_strarr(&nums_split);

    for (int i = 0; i < size * 2; i++) {
        free(names_split[i]);
    }

    mx_del_strarr(&strarr);
    free(text);

    return unique_islands;
}

