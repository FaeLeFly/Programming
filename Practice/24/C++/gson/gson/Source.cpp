#include <iostream>
#include <fstream>
#include <iomanip>
// тут должнен быть map
#include "json.hpp"
using json = nlohmann::json;
using namespace std;
int main()
{
	 ifstream l("in.json");
	 json j;
	 j = json::parse(l);
	json oj; 
	json jj;
	jj = j;
	oj.push_back(
		{
		{"userId",0},
		{"task_completed",0}
		}
	);
	int col = 0;
	int* deb = new int[j.size()];
		for (int g = 0; g < j.size(); g++) {
			if ((deb[col] != j[g]["userId"]) and (j[g]["userid"] != 0)) {
				deb[col] = j[g]["userId"];
				for ( int c=0 ; c < j.size(); c++) {
					if (deb[col] == j[c]["userId"])
						j[c]["userId"] = 0;
				}
				col++;
			}
		}
		int mxmx=0;
		for (int i = 0; i < col; i++) {
			if (deb[i] != 0) {
				mxmx++;
			}
		}
		int* mass = new int[mxmx];
		int c = 0;
		for (int i = 0; i < col; i++) {
			if (deb[i] != 0) {
				mass[c] = deb[i];
				c++;
			}
		}
		int count = 0;
		for ( int i = 0; i <mxmx; i++)
		{
			oj[i]["userId"] =mass[i];
			for (int a = 0; a < j.size(); a++) {
				if ((oj[i]["userId"]==jj[a]["userId"]) and (jj[a]["completed"].get<bool>() == true)) {
					count++;
				}
			}
			oj[i]["task_completed"]=count;
			count = 0;			
		}
ofstream o("out.json");
o << setw(4) << oj<< endl;
delete [] deb;
delete [] mass;
}
