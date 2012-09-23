//10444
//Multi-peg Towers of Hanoi
//Dynamic Programming;Ad hoc
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX 205
using namespace std;

int T[MAX][MAX];
int main() {
    int n=201, p=21, t=0;

    for(int i=0;i<=n;i++) {
        if (i<31)
            T[i][3] = (1<<i)-1;
        else
            T[i][3] = INT_MAX; //avoid overflow
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=4; j<=p; j++) {
            if (i<j) {
                T[i][j] = 2*i-1;
            } else {
                int minn = INT_MAX;
                for(int k=1;k<i;k++) {
                    int value = 2*T[k][j]+T[i-k][j-1];
                    if (value >= 0) //avoid overflow
                        minn = min(minn, value);
                }
                T[i][j] = minn;
            }
             
        }
    }

    while(cin >> n >> p, n | p) {
        cout << "Case " << ++t << ": " << T[n][p] << endl;
    }

    return 0;
}
