#include <iostream>;
#include <cmath>;
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double a, b, c, x1, y1, x2, y2, x3, y3,p,S;
	int num;
	cin >> num;
	if (num == 1) {
		cin >> a >> b >> c;
		p = (a + b + c) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "S=" << S;
	}
	else{
		cin >> x1 >> y1; cout << '\n';
		cin >> x2 >> y2; cout << '\n';
		cin >> x3 >> y3; cout << '\n';
		S = (((x1 - x3) * (y2 - y3)) - ((x2 - x3) * (y1 - y3)))*1/2;
		if (S < 0) {S= S * -1; };
		cout << "S=" << S;
	}
	return 0;
}
