#include "libmx.h"

bool mx_isspace(char c) {
	if (c == 32 || c == '\n' || c == '\t'
	|| c== '\v' || c == '\r' || c == '\f')
		return true;
	return false;
}

