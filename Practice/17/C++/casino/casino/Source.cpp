#include <iostream>;
using namespace std;
const int cell = 37;
int main() {
	int i = 0;
	int set[cell];
	int tes[cell];
	int count,last,black,red,stop;
	count = last = black = red = i;
	for (int j = 0; j < cell; j++) {
		set[j] = 0;
		tes[j] = 0;
	}
	while (i >= 0)
	{
		cin >> i;
		last += 1;
		for (int j = 0; j < cell; j++) {
			if (i == j) {
				set[j] += 1;
				tes[j] += 1;
				if (count <= set[j]) {
					count = set[j];
				}
			}
		}
		for (int j = 0; j < cell; j++) {
			if (count == set[j]) {
				cout << j << " ";
			}
		}
		cout << '\n';
		if (last > 12) {
			for (int j = 0; j < cell; j++) {
				tes[j] = 0;
				cout << j << " ";
			}
			cout << '\n';
			last = 0;
		}
		else {
			for (int j = 0; j < cell; j++) {
				if (tes[j] == 0) {
					cout << j << " ";
				}
			}
			cout << '\n';
		}
		if ((1 <= i && i<= 9 )|| (19 <= i && i<= 27)) {
			if (i % 2 == 1) red += 1;
			else black += 1;
		}
		else if ((11 <= i && i <= 18) ||( 29 <= i && i <= 36)) {
			if (i % 2 == 1) black += 1;
			else red += 1;
		}
		else if (i == 10 || i == 20 || i == 28) black += 1;
		cout << red << " " << black << '\n';
	}
		return 0;
}