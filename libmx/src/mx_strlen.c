#include "libmx.h"

int mx_strlen(const char *s) {
    if (s == 0) 
        return 0;
    int i = 0;
    for (; s[i] != '\0'; i++);
    return i;
}
