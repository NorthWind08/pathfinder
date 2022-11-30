#include "libmx.h"

char* mx_replace_substr(const char* str, const char* sub, const char* replace) {
    if(!str || !sub || !replace || mx_strlen(str) < mx_strlen(sub)) {
        return NULL;
    }
    int count_of_sub = mx_count_substr(str, sub);

    if (count_of_sub == 0) {
        char* fstr = mx_strnew(mx_strlen(str));
        mx_strcpy(fstr, str);
        return fstr;

    }
    
    int len = mx_strlen(str) + count_of_sub * (mx_strlen(replace) - mx_strlen(sub));
    char* newstr = mx_strnew(len);

    int index = 0;
    int count = 0;
    while(*str && count < len){
        index = mx_get_substr_index(str, sub);

        if(index == 0) {
            for (int i = 0; i < mx_strlen(replace); i++) {
                newstr[count] = replace[i];
                count++;
            }
            str += mx_strlen(sub);
            continue;
        }
        newstr[count] = *str;
        count++;
        str++;
    }
    
    return newstr;
}
