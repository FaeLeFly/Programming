#include <iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double a, b, O;
	char H;
	cin >> a >> H >> b;
	switch (H) {
	case'+':O = a + b;
		cout << O<<'\n';
		break;
	case '-':O = a - b;
		cout << O << '\n';
		break;
	case '*':O = a * b;
		cout << O << '\n';
		break;
	case '/':O = a / b;
		cout << O << '\n';
		break;
	default: cout << " число (+,-,/,*) число";
	}
		system("pause");
		return 0;
	}