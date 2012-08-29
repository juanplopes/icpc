//825
//Walking on the Safe Side
//Dynamic Programming;Ad hoc
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#define MAX 250
using namespace std;

int T[MAX][MAX];
int B[MAX][MAX];

int main() {
    int t; cin >> t;
    for(int tt=1; tt<=t; tt++) {
        int r, c; cin >> r >> c;

        string s;
        getline(cin, s);
        for(int i=0; i<r; i++) {
            getline(cin, s);
            stringstream sin(s);
            
            int a, b; sin >> a;
            while(sin >> b) {
                B[a-1][b-1] = tt;
            }
        }
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                int s = (i==0 && j==0 ? 1 : 0);
                if (i>0) s+= T[i-1][j];
                if (j>0) s+= T[i][j-1];
                T[i][j] = (B[i][j] != tt ? s : 0);
            }
        }

        if (tt>1) cout << endl;        
        cout << T[r-1][c-1] << endl;
    }
}
