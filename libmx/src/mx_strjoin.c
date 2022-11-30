#include "libmx.h"

char* mx_strjoin(const char* s1, const char* s2) {
    char* result;
 	if(s1 == NULL && s2 == NULL) {
 		return NULL;
 	} else if(s1 == NULL) {
 		result = mx_strdup(s2);
 		return result;
 	} else if(s2 == NULL) {
 		result = mx_strdup(s1);
 		return result;
 	} else {
	 	result = mx_strdup(s1);
		mx_strcat(result, s2);
		return result;
 	}
}
