#include "libmx.h"

void* mx_realloc(void* ptr, size_t size){
    unsigned char* cptr = (unsigned char *)ptr;
    unsigned char *newptr = malloc(size);

    if(!ptr) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        newptr[i] = cptr[i];
    }

    return newptr;
}
