#include <iostream>;
#include <cstdlib>;
#include <ctime>;
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian") ;
	int magic, guess;
	char da('1');
	unsigned random=2;
	srand(time(0));
	da:
	magic = rand() % 100 + 1;
	cout << "{ГПСЧ}\t" << '\n';
	for (int count = 0; count < 5; count++) {
		cin >> guess;
		if (magic == guess) {
			cout <<  "\nПоздравляю! Вы угадали. "<< "Было загадано\t"<<magic<<'\n';
			cout << "Хотите начать сначала? " <<"  "<< "{1-ДА}";
			cin >> da;
			if (da == '1')goto da; else return 0;
		}
		if (magic < guess)cout << "Загаданное число меньше\n"; else cout << "Загаданное число больше\n";
		if ((count + 1) % 5 == 0) {
			count = 0;
			cout << "\nВы проиграли. Было загадано:\t" << magic<<'\n';
			cout << "Хотите начать сначала?" << "{1-ДА}";
			cin >> da;
			if (da=='1') goto da; else  return 0;
		}
	}
	return 0;
}
