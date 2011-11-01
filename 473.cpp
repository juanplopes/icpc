//473
//Raucous Rockers
//Dynamic Programming;Longest Increasing Subsequence
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 10005
using namespace std;

int S[MAX], T[MAX];
char skip;
int main() {
    int n,t,m,cases;
    cin >> cases;
    while(cases--) {
        cin >> n >> t >> m;
        memset(T, 0x3F, sizeof(T));

        for(int i=1; i<=n; i++) {
            cin >> S[i];  
            if (i<n) cin >> skip;
        }
        
        int k=0; 
        T[0] = 0;

        for(int i=1;i<=n;i++) {
            for(int j=k; j>=0; j--) {
                int add = 0;
                if ((T[j]%t)+S[i] > t) add = t-T[j]%t;
                if (T[j]+S[i]+add <= T[j+1]) {
                    T[j+1] = T[j]+S[i]+add;
                    k=max(k, j+1);
                }
            }
        }
        
        int answer = 0;
        for(int i=0; i<=k && T[i] <= m*t; i++)
            answer = i;
        
        cout << answer << endl;
        if (cases) cout << endl;
    }

    return 0;
}
