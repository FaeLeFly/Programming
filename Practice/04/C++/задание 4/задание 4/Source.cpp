#include <iostream>; // без дополнительной переменной
int main() {
	int a, b;
	std::cin >> a >> b;
	a = a - b;
	b = a + b;
	a = b - a;
	std::cout << a <<'\n'<< b;
	return 0;
}
