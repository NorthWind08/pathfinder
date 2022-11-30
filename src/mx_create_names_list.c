#include "../inc/pathfinder.h"

t_list *mx_create_names_list(char **names) {

    t_list *list = mx_create_node(mx_strdup(names[0]));

    for (int j = 1; names[j] != NULL; j++) {

        if (!mx_node_in_list(list, names[j])) {
            mx_push_back(&list, mx_strdup(names[j]));
        }
    }
    return list;
}
