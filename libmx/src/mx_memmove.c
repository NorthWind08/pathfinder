#include "libmx.h"

void* mx_memmove(void* dst, const void* src, size_t len){
    unsigned char* temp = malloc(len);
    unsigned char* cdst = (unsigned char *)dst;
    unsigned char* csrc = (unsigned char *)src;
    temp = mx_memcpy(temp, csrc, len);
    cdst = mx_memcpy(cdst, temp, len);
    return dst;
}
