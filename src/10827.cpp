//10827
//Maximum sum on a torus
//Dynamic Programming;Maximum Sum Sub-rectangle
#include <iostream>
#include <climits>
#define MAX 160
using namespace std;

int T[MAX][MAX];

int main() {
    int n, a, cases;
    cin >> cases;
    while(cin >> n) {
        for(int i=1; i<=n; i++) {
            for(int j=1;j<=n;j++) {
                cin >> T[i][j];
                T[i+n][j] = T[i][j];
            }
        }
        
        for(int i=1; i<=2*n; i++)
            for(int j=1;j<=n; j++)
                T[i][j]+=T[i-1][j];

        int t = 0;
        for(int i=1;i<=2*n; i++) {
            for(int j=i;j<=min(i+n-1, 2*n);j++) {
                int smax=0, smin=0, ssum=0, tmax=0, tmin=0;
                for(int k=1;k<=n; k++)
                    ssum += T[j][k] - T[i-1][k];

                for(int k=1;k<=n; k++) {
                    int a = T[j][k] - T[i-1][k];
                    smax += a;
                    smin += a;
                    
                    tmax = max(tmax, smax);
                    tmin = min(tmin, smin);

                    if (smax < 0) smax = 0;
                    if (smin > 0) smin = 0;
                }
                t = max(t, max(tmax, ssum-tmin));
            }
        }
        
        cout << t << endl;
    }
    
    return 0;
}
