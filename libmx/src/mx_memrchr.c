#include "libmx.h"

void* mx_memrchr(const void* s, int c, size_t n){
	unsigned char *cs = (unsigned char*)s;
	for (size_t i = n; i > 0; i--) {
	if (cs[i] == c) {
		return &cs[i];
	}
	}
	return NULL;
}
