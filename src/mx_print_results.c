#include "../inc/pathfinder.h"

void print_results(int *distance, int startnode, int n, 
int **matrix, t_list *t_names, t_list **pred_lists) {

    int j = 0;
    int numbers[500];

    t_list **paths = malloc(sizeof(t_list*) * (n + 1));

    for (int i = 0; i < n; i++) {
        paths[i] = mx_create_node(malloc(sizeof(char)));
    }

    paths[n] = NULL;

    for (int i = 0; i < n; i++) {
        if (i != startnode) {
            numbers[0] = -1;
            numbers[1] = i;

            mx_index_of(
                paths, pred_lists, t_names,
                numbers, 2, i, startnode
            );

            free(paths[i]->data);
            mx_pop_front(&paths[i]);
        }
    }

    for (int i = 1; paths[i]; i++) {
        if (i != startnode) {
            mx_sort_list(paths[i], compare_routes);

            for (
                t_list *path = paths[i];
                path; path = path->next
            ) {
                int * way = path->data;

                for (j = 0; way[j + 1] != -1; j++);

                if (way[j] > startnode){
                    mx_print_delim();
                    // ========================================

                    mx_printstr("Path: ");
                    print_path(t_names, way, j);

                    mx_printchar('\n');
                    mx_printstr("Route: ");
                    print_route(t_names, way);

                    mx_printchar('\n');
                    mx_printstr("Distance: ");
                    print_distance(matrix, way, distance[i]);

                    mx_print_delim();
                    // ========================================
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != startnode) {
            t_list * temp = paths[i];
            mx_clear_list(&temp, true);
        }
    }
    
    for (int p = 0; p < n; p++) {
    mx_clear_list(&pred_lists[p], false); 
    }
    
    free(paths[startnode]->data);
	free(paths[startnode]);
    free(paths);
    free(pred_lists);
}

