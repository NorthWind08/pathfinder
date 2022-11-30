#include "../inc/pathfinder.h"

bool mx_node_in_list(t_list *list, char *data) {
    t_list *temp = list;

    while (temp != NULL) {
        char *str = temp->data;

        if (mx_strcmp(str, data) == 0) {
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}
