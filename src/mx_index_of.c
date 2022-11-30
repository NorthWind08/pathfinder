#include "../inc/pathfinder.h"

void mx_index_of(t_list **paths, t_list **lists, t_list * names, 
int *buf, int index, const int cur, int start) {

	if (cur == start) {
		buf[index++] = start;
		int i = 0;
		int j = 0;
		int *arr = malloc(index * sizeof(int));

		for (i = index - 2; i >= 0; i--) {
			arr[j++] = buf[i];
		}

		mx_push_back(&paths[buf[1]], arr);
	}
	else {
		for (
			t_list *temp = lists[cur];
			temp; temp = temp->next
		) {
			buf[index++] = *(int *)temp->data;
			mx_index_of(
				paths, lists, names, buf, index,
				*(int *)temp->data, start
			);
			index--;
		}
	}
}
