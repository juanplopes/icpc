//12493
//Stars
//Math;Prime Factorization;Euler's Totient
#include <iostream>
#include <cmath>
#define PP 100000
#define ull unsigned long long
using namespace std;

bool P[PP];

int main() {
    for(int i=2; i<PP; i++) {
		if (P[i]) continue;
		for(int j=i+i; j<PP; j+=i) {
			P[j] = true;
		}
	}
	
	ull n;
	while(cin >> n) {
		ull tot = 1;
		//cout << ">>" << n << endl; 
		for(ull i=2; i<=sqrt(n) && n>1; i++) {
			if (P[i]) continue;
			ull q=0;
		
			while(n%i==0) {
				n/=i;
				q++;
			}
			
			//if (q>0)
				//cout << i << " " << q << endl;
			if (q>0)
				tot *= (i-1) * (ull)pow(i, q-1);
		}
		if (n>1)
			tot *= n-1;
			
		cout << tot/2 << endl;
		
	}
}
