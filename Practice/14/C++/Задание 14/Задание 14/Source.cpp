#include<iostream>;
using namespace std;
int main() {
	long long x, n, y;
	cin >> n;
	y = 1; x = 0; 
	if (n == 0)  cout << x<<'\n'; 
	else {
		while (y <= n) {
			y *= 2;
			x++;
		}
		if (n = y)cout << x; else cout << x - 1<<'\n';
	}
	system("pause");
	return 0;
}