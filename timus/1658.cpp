//1658
//Sum of Digits
//Dynamic Programming;Ad hoc
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 105
using namespace std;

short S[1010][9000];
short T[1010][9000];

int main() {
    T[0][0] = 1;
    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=8100; j++) {
            S[i][j] = 102;
            for(int k=1; k<=9; k++) {
                int a = i-k;
                int b = j-k*k;
                if (a>=0 && b>=0 && T[a][b] && S[a][b]+1<S[i][j]) {
                    T[i][j] = k;
                    S[i][j] = S[a][b]+1;
                }
            }
        }
    }

    int t; cin >> t;
    while(t--) {
        int s1, s2; 
        cin >> s1 >> s2;
        
        if (s1 > 1000 || s2 > 8100 || S[s1][s2] > 100) {
            cout << "No solution" << endl;
            continue;
        }
        
        int n = S[s1][s2];
        for(int i=0; i<n; i++) {
            int d = T[s1][s2];
            cout << d;
            s1 -= d;
            s2 -= d*d;
        }
        cout << endl;
        
    }
}
