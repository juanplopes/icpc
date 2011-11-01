//907
//Winterim Backpacking Trip
//Dynamic Programming;Integer partition
#define MAX 602
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int T[MAX][MAX], S[MAX], n, k;

int main() {
    while(cin >> n >> k) {
        n++; k++;
        memset(T, 0, sizeof(T));

        S[0] = 0;
        for(int i=1; i<=n; i++) {
            cin >> S[i];
        }
        
        for(int i=1; i<=n; i++)
            T[i][1] = T[i-1][1]+S[i];
        
        for(int i=1; i<=k; i++)
            T[1][i] = S[1];

        for(int i=2; i<=n; i++) {
            for(int j=2; j<=k; j++) {
                T[i][j] = INT_MAX;
                for(int x=1; x<i; x++)
                    T[i][j] = min(T[i][j], max(T[x][j-1], T[i][1] - T[x][1]));
            }
        }
            
        cout << T[n][k] << endl;
    }    
}

