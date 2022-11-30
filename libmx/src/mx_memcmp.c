#include "libmx.h"

int mx_memcmp(const void* s1, const void* s2, size_t n){
    unsigned char* cs1 = (unsigned char*) s1;
    unsigned char* cs2 = (unsigned char*) s2;
    for (size_t i = 0; i < n; i++) {
        if(cs1[i] != cs2[i]) {
            return cs1[i] - cs2[i];
        }
    }
    return 0;
    
}
