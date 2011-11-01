//12147
//DNA Sequences
//Dynamic Programming;Longest Common Subsequence  
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];
int S[MAX][MAX];
string P, Q;

int main() {
    int k;
    while(cin >> k, k) {
        cin >> P >> Q;
        int p = P.size(), q = Q.size();
        
        for(int i=0; i<=p; i++) T[i][0] = S[i][0] = 0;
        for(int i=0; i<=q; i++) T[0][i] = S[0][i] = 0;

        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                if (P[i-1] == Q[j-1]) 
                    S[i][j] = S[i-1][j-1] + 1;
                else
                    S[i][j] = 0;
            }
        }
        
        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                T[i][j] = max(T[i-1][j], T[i][j-1]);

                for(int s=k; s<=S[i][j]; s++)
                    T[i][j] = max(T[i][j], T[i-s][j-s]+s);                
            }
        }
        cout << T[p][q] << endl;
    }

    return 0;
}
