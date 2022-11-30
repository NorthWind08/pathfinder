#include "libmx.h"

char* mx_strchr(const char* s, int c) {
	int i = 0;
	char* res ;
	while(s[i] != '\0') {
		if(s[i] == c) {
			res = (char*)&s[i];
			return res;
		}
		i++;
	}
	return 0;
}

