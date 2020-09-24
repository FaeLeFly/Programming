#include <iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int n; cin >> n;
	if ((n / 1) && (n / n) && !((n % 2)==0) && !((n % 3)==0)|| n==2||n==3) cout << "Простое";
	else if ((n / 2) || (n / 3))cout << "Составное";
		return 0;
}