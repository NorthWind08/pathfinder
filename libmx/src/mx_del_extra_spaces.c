#include "libmx.h"

char* mx_del_extra_spaces(const char*str){

    if(!str) {
		return NULL;
	}
    int i = 0;
    int k = 0;
    char* temp = mx_strnew(mx_strlen(str));
	while (str[i] != '\0') {
        if(!(mx_isspace(str[i]))) {
            temp[k] = str[i];
            k++;
        }
        if(!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            temp[k] = ' ';
            k++;
        }
        i++;
    }

    char* result = mx_strtrim(temp);
    mx_strdel(&temp);
    return result;
    
}
