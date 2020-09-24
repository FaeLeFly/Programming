#include <iostream>;
using namespace std;
int main() {
	double a, c;
	int b;
	cin >> a >> b;
	c = 1;
	if (b >= 0) {
		while (b > 0) {
			c *= a;
			b--;
		}
	}
	else {
		while (b < 0) {
			c *= a;
			b++;
		}
		c = 1 / c;
	}
	cout << c;
	return 0;
}
