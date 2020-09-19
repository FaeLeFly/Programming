#include <iostream>; // без дополнительной переменной
int main() {
	using namespace std;
	int a;  int b;
	cin >> a >> b;
	a = a - b;
	b = a + b;
	a = b - a;
	cout << a <<'\n'<< b;
	return 0;
}
#include <iostream>; // с дополнительной переменной
int main() {
	using namespace std;
	int a, b, c;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	cout << a << '\n' << b << '\n';
	return 0;
}