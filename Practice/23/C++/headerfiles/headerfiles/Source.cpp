#include <iostream>
#include <iomanip>;
#include "Taylor.h"
#include "factorial.h"
#include "combinations.h"
using namespace std;
int main() {
	int n = 0;
	cout << "n" << '\t' << "!n" << endl;
	for (int i = 0; i <= 10; i++) {
		cout << n <<'\t' << fact(n) << endl;
		n++;
	}
	double  pi = 3.14159265359;
	cout <<"x" << '\t' << "sin(x)" << endl;
	for (double x=0; x <= pi/4; x += pi / 180) {
		cout << setprecision(4)  << x << '\t'  <<sin(x, 5) << endl;
	}
	cout << "k" << '\t' <<  "C(k, 10)" << endl;
	n = 10;
	for (int k = 1; k <= 10; k++) {
		cout << k << '\t' << comb(k, n) << endl;
	}
}