#include "../inc/pathfinder.h"

int **mx_create_paths_matrix(t_list *names, char **lines,
int l_count, int islands_count) {

	int size = islands_count;
	int fro_i = -1;
	int to_i = - 1;

	int **paths = malloc(size * sizeof(int *));

	for (int i = 0; i < size; i++) {
		paths[i] = malloc(size * sizeof(int));

		for (int j = 0; j < size; j++) {
			paths[i][j] = 0;
		}
	}

	for (int i = 1; i < l_count; i++) {
		char **link = mx_create_link(lines[i]);

		int dist = mx_atoi(link[2]);

		fro_i = mx_get_by_value(names, link[0]);
		to_i = mx_get_by_value(names, link[1]);

		if (fro_i != -1 && to_i != -1) {
			paths[fro_i][to_i] = dist;
			paths[to_i][fro_i] = dist;
		}
		else {
			mx_del_strarr(&link);
			return NULL;
		}
		mx_del_strarr(&link);
	}

	return paths;
}
