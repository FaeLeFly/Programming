#include <iostream>;
using namespace std;
int main() {
	const char size = 10;
	char arr[size]{ "a???55661" };
	char hs[10]{ "a???55661" };
	char sh[10];
	int n;
	cin >> n;
	int b = n;
	while (n > 0) {
		n--;
		cin >> sh;
		for (int i = 0; i < size; i++) {
			if (arr[i] == sh[i]);
			else if (arr[i] == '?') hs[i] = sh[i];
			else {
				b--;
				break;
			}
		}
	}
	if (b == n) cout << "-1";
	else cout << hs;
	return 0;
}