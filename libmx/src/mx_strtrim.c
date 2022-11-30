#include "libmx.h"

char *mx_strtrim(const char *str) {
    int floor = 0;
    int roof = mx_strlen(str);
    for (; str[floor] != '\n';) {
        if (!mx_isspace(str[floor]))
            break;
        floor++;
    }
    if (floor == roof)
        return 0;
    roof--;
    for (; roof >= 0; roof--)
        if (!mx_isspace(str[roof]))
            break;
    roof--;
    int newlen = roof - floor + 2;
    char *ptr = mx_strnew(newlen);
    for (int i = 0; i < newlen; i++)
        ptr[i] = str[i + floor];
    return ptr;
}
