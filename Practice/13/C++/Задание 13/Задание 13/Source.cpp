#include <iostream>;
using namespace std;
int main() {
	int n; cin >> n;
	if ((n / 1) && (n / n) && !((n % 2)==0) && !((n % 3)==0)|| n==2||n==3) cout << "Простое\n";
	else if ((n / 2) || (n / 3))cout << "Составное\n";
	system("pause");
		return 0;
}