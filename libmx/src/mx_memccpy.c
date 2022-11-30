#include "libmx.h"

void* mx_memccpy(void* restrict dst, const void* restrict src, int c, size_t n) {
    unsigned char *csrc = (unsigned char *)src;
    unsigned char *cdest = (unsigned char *)dst;

    for (size_t i = 0; i < n; i++) {
        if(csrc[i] == (unsigned char)c) {
            cdest[i] = csrc[i];
            return (void*)&(cdest[i + 1]);
        } else {
            cdest[i] = csrc[i];
        }
    }
    return NULL;
}
