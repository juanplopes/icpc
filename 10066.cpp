//10066
//The Twin Towers
//Dynamic Programming;Longest Common Subsequence  
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 105
using namespace std;

int T[MAX][MAX];
int P[MAX], Q[MAX];

int main() {
    int p, q, tt=0;
    while(cin >> p >> q, tt++, p&&q) {
        memset(T, 0, sizeof(T));

        for(int i=0; i<p;i++) cin >> P[i];
        for(int i=0; i<q;i++) cin >> Q[i];

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
        cout << "Twin Towers #" << tt << endl;
        cout << "Number of Tiles : " << T[p][q] << endl;
        cout << endl;
    }

    return 0;
}
