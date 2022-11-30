#include "libmx.h"

char* mx_strcat(char* restrict s1, const char* restrict s2) {
	int i;
	int len = mx_strlen(s1);
	for(i = 0; s2[i] != '\0'; i++) {
		s1[i + len] = s2[i];
	}
	s1[i + len] = '\0';
	return s1;
}

