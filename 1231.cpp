//1231
//ACORN
//Dynamic Programming;Ad hoc
#include <iostream>
#include <string>
#include <cstring>
#define MAX 2001
using namespace std;

int S[MAX][MAX], T[MAX][MAX], M[MAX];
char skip;
int main() {
    int cases; cin >> cases;
    while(cases--) {
        memset(S, 0, sizeof(S));
        memset(M, 0, sizeof(M));
        int t, h, f;
        cin >> t >> h >> f;

        for(int i=0; i<t; i++) {
            int k, a; cin >> k;
            while(k--) {
                cin >> a;
                S[a][i]++;
            }
        }

        for(int i=h; i>=0; i--) {
            for(int j=0; j<t; j++) {
                int move = i+f<=h ? M[i+f] : 0;
                int stay = i+1<=h ? T[i+1][j] : 0;
                T[i][j] = max(move, stay) + S[i][j];
                M[i] = max(M[i], T[i][j]);
            }
        }
        
        cout << M[0] << endl;
    }

    return 0;
}

