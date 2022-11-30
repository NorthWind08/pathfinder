#include "libmx.h"

void* mx_memmem(const void* big, size_t big_len, const void* little, size_t little_len){
    unsigned char* cbig = (unsigned char*)big;
    unsigned char* clittle = (unsigned char*)little;

    if(big_len < little_len || big_len == 0 || little_len == 0) {
        return NULL;
    }
    
    while (*cbig) {
        if (mx_memcmp(cbig, clittle, little_len - 1) == 0)
            return cbig;
        cbig++;
    }
    return NULL;
}

