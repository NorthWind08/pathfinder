#include "libmx.h"

void mx_clear_list(t_list **list, bool free_data) {
	if (list == NULL || *list == NULL) {
		return;
	}

	while (*list) {
		t_list *temp = (*list)->next;
		if (free_data) {
			free((*list)->data);
		}
		free(*list);
		*list = temp;
	}
}
