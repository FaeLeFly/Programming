#include <iostream>;
#include <cmath>;
using namespace std;
int main() {
	double g, v0, x0, t, x,o;
	g = 9.8;
	cout << "x0="; cin >> x0;
	cout << "v0="; cin >> v0;
	cout << "t="; cin >> t;
	x = x0 + v0 * t - g * t * t / 2;
	o = abs(x - x0);
	cout << "Distance=" << o<<'\n';
		system("pause");
		return 0;
}