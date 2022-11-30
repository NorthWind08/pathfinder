#include "libmx.h"

void* mx_memchr(const void* s, int c, size_t n){
    unsigned char* cs = (unsigned char*)s;
    for (size_t i = 0; i < n; cs++, i++){
        if(*cs == c) {
            return cs;
        }
    }
    return NULL;
}
