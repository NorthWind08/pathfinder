#include "../inc/pathfinder.h"

bool compare_routes(void *a, void *b) {
    int *r1 = (int *)a;
    int *r2 = (int *)b;
    int i = 0;

    for ( 
        ;r1[i] != -1 && r2[i] != -1;
    ) {
        if (r1[i] != r2[i]) {
            break;
        }
        i++;
    }

	return r1[i] > r2[i];
}
