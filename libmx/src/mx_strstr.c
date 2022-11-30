#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    char *temphaystack = (char *)s1;
    char *tempneedle = (char *)s2;
    
    if ((!s1) || (!s2))
        return NULL;
    if (!mx_strlen(s2))
        return temphaystack;
    while (*temphaystack) {
        if (!mx_strncmp(temphaystack, tempneedle, mx_strlen(tempneedle)))
            return temphaystack;
        temphaystack++;
    }
    return NULL;
}
