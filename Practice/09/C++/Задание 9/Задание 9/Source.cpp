#include <iostream>;
int main() {
	using namespace std;
	setlocale(LC_ALL, "rus");
	int m1, m2, m, h1, h2;
	char c;
	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;
	if ((h1 - h2 )== 0) {
		m = (60 - m1) - (60 - m2);
		if ((-16 < m) and (m < 16)) { cout << "встреча состоится"; }
		else { cout << "Встреча не состоится"; }
	}
	else {
		if ((-2 < (h1-h2)) and ((h1-h2)< 2))
		{
			if ((m1 > 45) and (m2 < 15)) {
				m = 60 - m1 + m2;
				if (m < 16) { cout << "Встреча состоится"; }
				else { cout << "Встреча не состоится"; }
			}
			else {
				if ((m2 > 45) and (m1 < 15)) {
					m = 60 - m2 + m1;
					if (m < 16) { cout << "Встреча состоится"; }
					else { cout << "Встреча не состоится"; }
				}
				else {
					if ((m1 > 15) and (m2 < 45)) {
						m = (60 - m1) - (60 - m2);
						if ((m < 16) and (m > -16)) { cout << "Встреча состоится"; }
						else { cout << "Встреча не состоится"; }
					}
					if ((m2 > 15) and (m1 < 45)) {
						m = (60 - m2) - (60 - m1);
						if ((m < 16) and (m > -16)) { cout << "Встреча состоится"; }
						else { cout << "Встреча не состоится"; }
					}
				}
			}
		}
		else { cout << "Встреча не состоится"; }
	}
	return 0;
}