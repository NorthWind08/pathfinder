#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int nbr2 = nbr;
    int j = 0;
    int tmp;

    while(nbr != 0) {
        nbr /= 16;
        j++;
    }
    if (j == 0)
        return 0;

    char *string = mx_strnew(j);
    for (int i = j - 1; i >= 0; i--) {
        tmp = nbr2 % 16;

        if (tmp < 10)
            string[i] = tmp + 48;
        else 
            string[i] = tmp + 87;

        nbr2 /= 16;
    }
    return string;
}
