//11003
//Boxes
//Dynamic Programming;Longest Increasing Subsequence
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX 10005
using namespace std;

int T[MAX];
int main() {
    int n, w, c;
    while(cin >> n, n) {
        memset(T, 0, sizeof(T));
        
        int k = 0;
        T[0] = INT_MAX;
        for(int i=1; i<=n; i++) {
            cin >> w >> c;
            for(int j=k; j>=0; j--) {
                int next = min(T[j]-w, c);
                if (next >= T[j+1]) {
                    T[j+1] = next;
                    k=max(k, j+1);
                }
            }
        }
        
        cout << k << endl;
    }

    return 0;
}
