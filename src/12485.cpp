//12485
//Perfect Choir
//Misc;Ad hoc
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int T[10005];

int main() {
    int n;
    while(cin >> n) {
		memset(T, 0, sizeof(T));
		int total = 0;
        for(int i=0; i<n; i++) {
			int a; cin >> a;
			total += a;
			T[i] = a;
		}

		if (total % n != 0) {
			cout << -1 << endl;
			continue;
		}
		
		int media = total / n;
		int maior = 0;
		for(int i=0; i<n; i++) {
			if (T[i] > media)
				maior += T[i] - media;
		}
		
		cout << maior +1 << endl;
    }
}
