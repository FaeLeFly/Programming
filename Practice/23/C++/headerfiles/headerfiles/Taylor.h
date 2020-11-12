#include "factorial.h"
#include <cmath>
#ifndef Taylor_H
#define Taylor_H
double sin(double x, int k) {
	int m = -1; double fx = 0, sum=0;
	for (int i = 0; i < k; i++) {
	    fx = pow(m, i) * pow( x, 2 * i + 1) / fact(2 * i + 1);
		sum += fx;
	}
	return sum;
}
#endif
