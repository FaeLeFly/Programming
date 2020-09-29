#include <iostream>;
using namespace std;
int main() {
	int x,y,n;
	x = 1; y = 2;
	cin >> n;
	while (n > 1) {
		x = x * y;
		y++;
		n--;
	}
	cout << x<<'\n';
	system("pause");
	return 0;
}