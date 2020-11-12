#include "factorial.h"
#ifndef combinations_H
#define combinations_H
int comb(int k, int n) {
	int bom;
	bom = fact(n) /( fact(k) * fact(n - k));
	return bom;
}
#endif
