//12488
//Start Grid
//Misc;Ad hoc
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int L[30], C[30];

int abs(int n) {
	if (n < 0) return -n;
	return n;
}

int main() {
    int n;
    while(cin >> n) {
		for(int i=0; i<n; i++)
			cin >> L[i];
		
		for(int i=0; i<n; i++)
			cin >> C[i];

		int total = 0;
		for(int i=0; i<n; i++) {
			int cara = C[i];
			for(int j=n-1; j>i; j--) {
				if (L[j]==cara) {
					int t = L[j];
					L[j] = L[j-1];
					L[j-1] = t;
					total++;
				}
			}
		}
			
		cout << total << endl;
    }
}
