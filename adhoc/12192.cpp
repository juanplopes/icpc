#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T[1001][501];
int S[1001];

int main() {
    int n, m, q;
    while(cin >> n >> m, n|m) {
        memset(S, 0, sizeof(S));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i-j+max(n,m)][S[i-j+max(n,m)]++];
            }
        }
        
        cin >> q;
        while(q--) {
            int L, U;
            cin >> L >> U;
            int maxx = 0;
            for(int i=0;i<2*max(n,m); i++) {
                int a = lower_bound(T[i], T[i]+S[i], L) - T[i];
                int b = upper_bound(T[i], T[i]+S[i], U) - T[i];
                maxx = max(maxx, b-a);
            }
            cout << maxx << endl;
        }
        
        cout << "-" << endl;
    }
}
