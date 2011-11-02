//10635
//Prince and Princess
//Dynamic Programming;Longest Increasing Subsequence
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 255*255
using namespace std;

int P[MAX], Q[MAX], M[MAX];

int main() {
    int n, p, q, tt=0, temp;
    cin >> n;
    while(cin >> n >> p >> q) {
        memset(P, 0, sizeof(P));
        q++; p++;
        for(int i=1;i<=p;i++) {
            cin >> temp;
            P[temp] = i;
        }
        
        for (int i=1;i<=q;i++) {
            cin >> temp;
            Q[i] = P[temp];
        }
        
        int k=0; M[0]=0; 
        for(int i=1;i<=q;i++) {
            if (Q[i] > M[k]) {
                k++; M[k] = Q[i];
            } else {
                int j = (int)(lower_bound(M, M+k+1, Q[i])-M);
                if (Q[i] > M[j]) j++;
                M[j] = Q[i];
            }
        }
        
        cout << "Case " << ++tt << ": " << k << endl;
    }
    
    return 0;
}
