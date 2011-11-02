//10723
//Cyborg Genes
//Dynamic Programming;Longest Common Subsequence  
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX], D[MAX][MAX];
string P, Q;

int main() {
    int p, q, t, tt=0;
    cin >> t;
    getline(cin, P);
    while(tt++ < t) {
        getline(cin, P);
        getline(cin, Q);
        int p = P.size(), q = Q.size();
        
        for(int i=0; i<=p; i++) { T[i][0] = 0; D[i][0] = 1; }
        for(int i=0; i<=q; i++) { T[0][i] = 0; D[0][i] = 1; }

        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                D[i][j] = 0;
                if (P[i-1] == Q[j-1]) {
                    T[i][j] = T[i-1][j-1] + 1;
                    D[i][j] = D[i-1][j-1];
                }
                else {
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                    if (T[i-1][j] == T[i][j]) D[i][j] += D[i-1][j];
                    if (T[i][j-1] == T[i][j]) D[i][j] += D[i][j-1];
                }
            }
        }
        
        cout << "Case #" << tt << ": " << p+q-T[p][q] << " " << D[p][q] << endl;
    }
    
    return 0;
}
