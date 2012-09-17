//12482
//Short Story Competition
//Misc;Ad hoc
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n, li, c;
    while(cin >> n >> li >> c) {
        string s;
		int pag = 1;
		int car = 0;
		for(int i=0; i<n; i++) {
			if (car > 0) car++;
	
			cin >> s;
			if (car + s.size() > c) {
				pag++;
				car = s.size();
			} else {
				car += s.size();
			}
			//cout << s<< " " << pag << " " << car << endl;
		}
		cout << ceil(pag/(double)li) << endl;
		
		
		
    }
}
