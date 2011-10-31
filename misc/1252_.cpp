#include <iostream>
#include <climits>
#define MAX 2048
using namespace std;

int BC[MAX], T[128];

int main() {
    for(int i=0; i<MAX; i++) {
        int tmp = i;
        while(tmp) {
            BC[i] += tmp&1;
            tmp >>= 1;
        }
    }
    int m, n;
    while(cin >> m >> n, m|n) {
        char c;
        for(int i=0; i<n; i++) {
            T[i] = 0;
            for(int j=0; j<m; j++) {
                cin >> c;
                T[i] *= 2; T[i] += c-'0';
            }
        }
        
        int maxx = 0;
        for(int i=0; i<n; i++) {
            int minn = INT_MAX;
            for(int k=0; k<(1<<m); k++) {
                bool ok = true;
                for(int j=0; j<n; j++)
                    ok &= i==j || ((T[i] ^ T[j]) & k) > 0;

                if (ok) minn = min(minn, BC[k]);
            }
            maxx = max(maxx, (m==0?0:minn));
        }
        cout << maxx << endl;
    }
}
