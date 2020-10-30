#include <iostream>
using namespace std;
void printBMI(double BMI) {
	if (BMI < 18.5) cout << "Underweight";
		else if (BMI < 25)cout << "Normal weight";
			else if (BMI < 30)cout << "Overweight";
				else cout << "Obesity";
}
double BMI(double weight, double height) {
	double BMI;
	BMI= weight / (height * height);
	 printBMI(BMI);
	 return 0;
}
int main() {
	double weight, height;
	std::cin >> weight >> height;
	BMI(weight, height);
}

