#include "../inc/pathfinder.h"

void print_distance(int **weights_mat, int *indice, int distance) {

    mx_printint(weights_mat[indice[0]][indice[1]]);

    int i = 1;
    int j = 2;

    for (; indice[j] != -1; i++, j++) {
        mx_printstr(" + ");
        mx_printint(weights_mat[indice[i]][indice[j]]);
    }

    if (
        distance != weights_mat[indice[i - 1]][indice[j - 1]]
    ) {
        mx_printstr(" = ");
        mx_printint(distance);
    }

    mx_printchar('\n');
}
