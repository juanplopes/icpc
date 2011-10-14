#include <iostream>
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
				T[i+n][j] = T[i][j+n] = T[i+n][j+n] = T[i][j];
			}
		}
		
		for(int i=1; i<=2*n; i++)
			for(int j=1;j<=2*n;j++)
				T[i][j]+=T[i-1][j];

		int maxt = 0;
		for(int i=1;i<=2*n; i++) {
			for(int j=i;j<=min(i+n-1, 2*n);j++) {
				for(int m=1;m<=2*n; m++) {
					int t=0, s=0;
					for(int k=m;k<=min(m+n-1, 2*n);k++) {
						int a = T[j][k] - T[i-1][k];
						if (s+a>=0)
							t = max(t, s+=a);
						else
							s = 0;
					}
					maxt = max(maxt, t);
				}
			}
		}
		
		cout << maxt << endl;
	}
    
    return 0;
}
