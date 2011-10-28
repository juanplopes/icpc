#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];

int main() {
    int t; cin >> t; t=0;
    string P, Q; 
    int k;
    while(cin >> P >> k) {
        cout << P << endl;
        Q = string(P.rbegin(), P.rend());
        int p = P.size(), q=Q.size();
        
        for(int i=1; i<=p; i++)
            for(int j=1; j<=q; j++)
                T[i][j] = T[i-1][j-1] + (P[i-1] == Q[j-1] ? 0 : 1);
        
        int maxx = 0;
        for(int i=0; i<=p; i++) {
            for(int j=i; j<=q; j++) {
                if (T[j][j]/2 - T[i][i]/2 <= k) {
                    cout << j-i << " " << T[j][j] << " " << T[i][i] << endl;
                    maxx = max(maxx, j-i);
                }
            }
  
        }

        cout << maxx << endl;
    }
    
    return 0;
}
