//1207
//AGTC
//Dynamic Programming;Edit Distance
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];
string P, Q;


int main() {
    int p, q;
    while(cin >> p >> P >> q >> Q) {
        for(int i=0; i<=p; i++) { T[i][0] = i; }
        for(int i=0; i<=q; i++) { T[0][i] = i; }

        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                if (P[i-1] == Q[j-1])
                    T[i][j] = T[i-1][j-1];
                else
                    T[i][j] = min(min(T[i-1][j], T[i][j-1]), T[i-1][j-1])+1;
            }
        }
        
        cout << T[p][q] << endl;
    }
    
    return 0;
}
