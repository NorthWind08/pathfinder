#include "libmx.h"

void mx_printint(int num) {
    int buf[20];
    int i = 0;
    if (num == 0) {
        mx_printchar('0');
    }
    if (num == -2147483648) {
        mx_printint(-214748364);
        mx_printchar('8');
        return;
    }
    else {
        if (num < 0) {
        num *= -1;
        mx_printchar('-');
        }
        for (; num != 0; i++) {
            buf[i] = num % 10;
            num /= 10;
        }
        for (i--; i >= 0; i--) {
            mx_printchar(buf[i] + 48);
        }
    }
}
