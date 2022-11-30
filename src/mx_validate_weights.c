#include "../inc/pathfinder.h"

void mx_validate_weights(char **weights) {
    int sum = 0;

    for (int i = 0; weights[i]; i++) {
        sum += mx_atoi(weights[i]);
    }
    
    if (
        sum >= MAX_INT ||
        sum <= -MAX_INT
    ) {
        mx_printerr("error: sum of bridges lengths is too big\n");

        for (int i = 0; weights[i]; i++) {
            free(weights[i]);
        }
        free(weights);

        exit(1);
    }
}
