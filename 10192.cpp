//10192
//Vacation
//Dynamic Programming;Longest Common Subsequence  
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];
string P, Q;

int main() {
    int p, q, tt=0;
    while(getline(cin, P), P!="#") {
        tt++;
        getline(cin, Q);
        int p = P.size(), q = Q.size();
        
        memset(T, 0, sizeof(T));

        for(int i=0; i<=p; i++) T[i][0] = 0;
        for(int i=0; i<=q; i++) T[0][i] = 0;

        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                if (P[i-1] == Q[j-1])
                    T[i][j] = T[i-1][j-1] + 1;
                else
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
        cout << "Case #" << tt << ": you can visit at most " << T[p][q] << " cities." << endl;
    }

    return 0;
}
