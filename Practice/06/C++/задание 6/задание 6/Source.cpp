#include <iostream>;
#include <cmath>;
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double a, b, c, d,x1,x2;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if ((d > 0) && (a!=0)) {
		x1 =( -b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		cout << "x1="<<x1<<'\n'<<"x2=" << x2;
	} 
	else {
		if ((a == 0) && (d > 0)) {
			x1 = -1 * c / b;
			cout << "x=" << x1;
		};
			if (d == 0) {
				x1 = -b / 2 * a;
				cout << "x=" << x1;
			}
		else{
			if (d<0) {
				cout << "нет действительных корней";
		}
		}
	}
	system("pause");
	return 0;
}