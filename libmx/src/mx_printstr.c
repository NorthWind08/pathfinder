#include "libmx.h"

void mx_printstr(const char *s) {
    int len = mx_strlen(s);
    if (len == 0)
        return;
    write(1, s, len);
}
