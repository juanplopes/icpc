//12484
//Cards
//Dynamic Programming;Minimax
#include <iostream>
#include <cstring>
#include <algorithm>
#define ull long long
using namespace std;

ull T[10006], Q[10006], M[10006];


int main() {
    int n;
    while(cin >> n) {
        for(int i=1; i<=n; i++) {
            cin >> M[i];
            M[i]+=M[i-1];
        }

        memset(T, 0, sizeof(ull)*n);

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=n-i; j++)
                Q[j] = M[j+i]-M[j] - min(T[j], T[j+1]);

            swap(T, Q);
        }
		
        cout << T[0] << endl;
    }

}
