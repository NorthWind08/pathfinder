#include "libmx.h"

int mx_bubble_sort(char **arr, int len) {
    int swaps = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j+1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}
