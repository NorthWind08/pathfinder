#include "../inc/pathfinder.h"

void *mx_get_by_index(t_list *list, int i) {
	int j = 0;

	for (
		t_list *temp = list;
		temp; temp = temp->next
	) {
		if (j++ == i) {
			return temp->data;
		}
	}

	return NULL;
}

int mx_get_by_value(t_list *list, void *value) {
	int i = 0;

	for (
		t_list *temp = list; temp;
		temp = temp->next, i++
	) {
		if (!mx_strcmp(value, temp->data)) {
			return i;
		}
	}

	return -1;
}

