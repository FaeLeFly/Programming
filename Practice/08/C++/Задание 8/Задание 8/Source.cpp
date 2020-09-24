#include <iostream>;
int main() {
	using namespace std;
	setlocale(LC_ALL, "rus");
	double a, b,O;
		char H;
		cin >> a >> H >> b;
		switch(H) {
		case'+':O=a+b;
			cout << O;
			break;
		case '-':O = a - b;
			cout << O;
			break;
		case '*':O = a * b;
			cout << O;
			break;
		case '/':O = a / b;
			cout << O;
			break;
		default: cout << " число (+,-,/,*) число";
		}
		return 0;		
}