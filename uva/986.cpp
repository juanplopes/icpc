//986
//How Many?
//Dynamic Programming;Ad hoc
#include <iostream>
#include <cstring>
using namespace std;

int T[50][50][50][2];
    
int main() {
    int n, r, h;
    
    while(cin >> n >> r >> h) {
        memset(T, 0, sizeof(T));
        T[0][0][0][0] = 1;

        for(int i=1; i<=2*n; i++) {
            for(int j=0; j<=2*n; j++) {
                for(int k=0; k<=2*n; k++) {
                    if (j<2*n) {
                        T[i][j][k][0] += T[i-1][j+1][k][0]; 
                        
                        if (j+1==h && k>0)
                            T[i][j][k][0] += T[i-1][j+1][k-1][1];
                        else if (j+1!=h)
                            T[i][j][k][0] += T[i-1][j+1][k][1];
                    }

                    if (j>0) {
                        T[i][j][k][1] += T[i-1][j-1][k][0] + T[i-1][j-1][k][1];
                    }
  
                }
            }
        }
        
        cout << T[n*2][0][r][0] << endl;

    }
}
