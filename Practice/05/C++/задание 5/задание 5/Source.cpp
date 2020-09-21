#include <iostream>;
int main() {
	using namespace std;
	double g, v0, x0, t,x;
	g = 9.8;
	 cout << "x0="; cin >> x0;
	 cout << "v0="; cin >> v0;
	 cout << "t="; cin >> t;
	x = x0 + v0 * t - g * t * t / 2;
	cout << "Distance=" << x;
	return 0;
}