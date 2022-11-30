#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str)
        return -1;
    if (c == 0)
        return -1;

    bool state = true;
    size_t wordcount = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            state = true;
        else if (state == true) {
            state = false;
            wordcount++;
        }
        i++;
    }
    return wordcount;
}
