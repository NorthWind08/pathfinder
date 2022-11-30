#include "libmx.h"

double mx_pow(double num, unsigned int pow) {
	double result = 1;

	// if (pow == 0) {
	// 	return result;
	// }
	if (pow > 0) {
		for (unsigned int i = 0; i < pow; i++) {
			result = result * num;
		}
	}
	return result;
}

