#include "../inc/pathfinder.h"

void dijkstra(int **matrix, int n, int start_node, t_list *t_names) {

    int cost[n][n];
    int distance[n];
    int pred[n];
    int visited[n];
    int arr_for_nums[200];

    int count;
    int min_dist;
    int next_node;
    int i;
    int j;
    int count_nums = 0;

    t_list **pred_lists = malloc(n * sizeof(t_list *));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                cost[i][j] = MAX_INT;
            }
            else {
                cost[i][j] = matrix[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[start_node][i];
        visited[i] = 0;

        pred[i] = start_node;
        int t = start_node;

        pred_lists[i] = mx_create_node((void *)&t);
    }

    distance[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while (count < n - 1) {
        min_dist = MAX_INT;

        for (i = 0; i < n; i++) {
            if (distance[i] < min_dist && !visited[i]) {
                min_dist = distance[i];
                next_node = i;
            }
        }

        visited[next_node] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i]) {

                if (
                    min_dist + cost[next_node][i] < distance[i] &&
                    min_dist + cost[next_node][i] > 0
                ) {
                    arr_for_nums[count_nums] = next_node;
                    distance[i] = min_dist + cost[next_node][i];
                    pred[i] = next_node;
                    mx_clear_list(&pred_lists[i], false);
                    pred_lists[i] = mx_create_node((void *)(&arr_for_nums[count_nums++]));
                }

                else if (
                    min_dist + cost[next_node][i] == distance[i] &&
                    min_dist + cost[next_node][i] > 0
                ) {
                    arr_for_nums[count_nums] = next_node;
                    mx_push_front(
                        &pred_lists[i], 
                        (void *)(&arr_for_nums[count_nums++])
                    );
                }
            }
        }
        count++;
    }

    print_results(
        distance, start_node, n, 
        matrix, t_names, pred_lists
    );
}
