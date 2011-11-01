//1239
//Greatest K-Palindrome Substring
//Dynamic Programming;Ad hoc
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];

int main() {
    int t; cin >> t; t=0;
    string P;
    int k;
    while(cin >> P >> k) {
        int p = P.size();

        int maxx=0;        
        for(int i=p; i>=1; i--) {
            for(int j=i; j<=p; j++) {
                T[i][j] = T[i+1][j-1] + (P[i-1] == P[j-1] ? 0 : 1);

                if (T[i][j] <= k)
                    maxx = max(maxx, j-i+1);
            }
        }

        cout << maxx << endl;
    }
    
    return 0;
}
