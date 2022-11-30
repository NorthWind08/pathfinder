#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;
    unsigned long num = 0;
    unsigned long base = 1;

    if (hex != NULL) {
        while (hex[len])
            len++;
    }   
    else {
        return num;
    } 

    for (int i = 0; i <= len; i++) {
        char ch = hex[len - i];
        if (ch >= '0' && ch <= '9') {
            num += (ch - 48) * base;
            base *= 16;
        }
        if (ch >= 'A' && ch <= 'F') {
            num += (ch - 55) * base;
            base *= 16;
        }
        if (ch >= 'a' && ch <= 'f') {
            num += (ch - 87) * base;
            base *= 16;
        }
    }
    return num;
}
