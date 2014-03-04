//1524
//Cafeteria Queue
//Dynamic Programming;Ad hoc
#include <iostream>
#include <cstdio>
using namespace std;

int T[1100][1100];
int L[1100][1100];
int V[1100][1100];

int main() {
    int n, k, run = 0;
    while(scanf("%d %d", &n, &k) != EOF) {
        run++;
        
        T[1][1] = 0;
        L[1][1] = 0;
        V[1][1] = run;
        
        for(int i=2; i<=n; i++) {
            int temp; scanf("%d", &temp);
            
            for(int j=1; j<=i; j++) {
                T[i][j] = 0x3f3f3f3f;
                
                if (V[i-1][j]) {
                    T[i][j] = min(T[i][j], T[i-1][j] + (temp-L[i-1][j]));
                    V[i][j] = run;
                }
                
                if (j > 1 && V[i-1][j-1]) {
                    T[i][j] = min(T[i][j], T[i-1][j-1]);
                    V[i][j] = run;
                }

                L[i][j] = temp;
            }
        }
        
        cout << T[n][k] << endl;
    }
}

