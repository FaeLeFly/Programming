#include <iostream>;
using namespace std;
int main() {
	long long s, l1, l2, r1, r2, x1, x2;
	cin >> s >> l1 >> r1 >> l2 >> r2;
	x1 = l1;
	x2 = 0;
	if (x1 + r2 < s) {
		x2 = r2;
		if (s - x2 > r1) { cout << "-1\n"; }
		else { x1 = s - r2; }
	}
	else {
		if (l1 + l2 > s) { cout << "-1\n"; }
		else { x2 = s - x1; }
	}
	if (x1 + x2 == s) { cout << x1 << " " << x2 << '\n'; }
	system("pause");
	return 0;
}