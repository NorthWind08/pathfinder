#include "libmx.h"

int mx_sqrt(int n) {
	for (int i = 1; i <= n / i; i++) {
		if (i * i == n)
			return i;
	}

	return 0;
}
