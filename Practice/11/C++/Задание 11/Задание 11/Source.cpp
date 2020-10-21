#include <iostream>;
using namespace std;
int main() {
	int a, c;
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
	cout << c<<'\n';
	system("pause");
	return 0;
}
