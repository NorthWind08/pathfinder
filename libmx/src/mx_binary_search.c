#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;
    int mid;
    int index = -1;

    while (low <= high) {
        mid = (high + low) / 2;

        if (mx_strcmp(arr[mid], s) > 0) {
            high = mid - 1;
        }
        else if (mx_strcmp(arr[mid], s) == 0) {
            index = mid;
            *count += 1;
            break;
        }
        else {
            low = mid + 1;
        }
        *count += 1;
    }
    if (index == -1)
        *count = 0;
    return index;
}
