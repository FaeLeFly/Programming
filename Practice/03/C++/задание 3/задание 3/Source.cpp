#include <iostream>;
int main() {
	using namespace std;
	int a, b;
	cout << "INT ; INT\n";
	cin >> a >> b;
	cout << a * b <<'\n'<< a / b <<'\n'<< a + b <<'\n'<< a - b << '\n';
	double c, d;
	cout << "DOUBLE ; DOUBLE\n";
	cin >> c >> d;
	cout << c * d << '\n' << c / d << '\n' << c + d << '\n' << c - d << '\n';
	int q;
	double w;
	cout << "INT ; DOUBLE\n";
	cin >> q >> w;
	cout << q * w << '\n' << q / w << '\n' << q + w << '\n' << q - w << '\n';
	double e;
	int r;
	cout << "DOUBLE ; INT\n";
	cin >> e >> r;
	cout << e * r << '\n' << e / r << '\n' << e + r << '\n' << e - r << '\n';
	return 0;
}