#include <iostream>
#include <string>
using namespace std;
int main() {
	int cash; cin >> cash;
	int bottle; cin >> bottle;
	string* entity = new string[bottle]; int* cost = new int[bottle]; int* amount = new int[bottle];
	for (int i = 0; i < bottle; i++) {
		cin >> entity[i] >> cost[i] >> amount[i];
	}
	int maxcash; int maxamount; int rest=0; int buybottle; int equl=0 ; string gdeal; int gbottle=0;
	for (int i = 0; i < bottle; i++) {
		if (cash >= cost[i] && equl == 0) {
			buybottle = cash / cost[i];
			maxcash = buybottle * cost[i];
			maxamount = buybottle * amount[i];
			equl++;
		}
	}
		for (int i = 0; i < bottle; i++) {
			if (cash >= cost[i]) {
				buybottle = cash / cost[i];
				if (buybottle * cost[i] >= maxcash && buybottle * amount[i] >= maxamount) {
					rest = cash - (buybottle * cost[i]);
					maxamount = buybottle * amount[i];
					gdeal = entity[i]; 
					gbottle = buybottle;
				}
			}
		}
		if (equl != 0) {
			cout << gdeal << " " << gbottle << endl;
			cout << maxamount << endl;
			cout << rest;
		}
		else cout << "-1";
		return 0;
}