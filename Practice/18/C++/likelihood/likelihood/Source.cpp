#include <iostream>;
#include <iomanip>;
using namespace std;
int main() {
	const int mb = 255;
	char joke[mb];
	double kas = 1;
	double mas = 0; 
	double count = 0;
	double sount = 0; 
	char nem[]{ "halloklempnerdasistfantastischfluggegecheimen" };
	cin >> joke;
	for (int i = 0; i < mb; i++) {
		for (int j = 0; j < mb; j++) {
			if (joke[i] == joke[j]) {
				sount += 1;
			}
		}
		for (int j = 0; j < 45; j++) {
			if (joke[i] == nem[j] ) {
				count += 1;
				nem[j] == '1';
			}
		}
		if ((count && sount) > 0) {
			mas = count / 45 * sount;
			kas = kas*mas;
		}
		sount = 0;
		count = 0;

	}
	if (kas == 1)cout << "Нет таких букв(звуков) в стоп слове";
	else cout << setprecision(16)<< kas;

	return 0;
}