#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 101
using namespace std;

int KMAX[MAX][10], KMIN[MAX][10], W[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int prepend(int a, int b) {
    return a*(int)pow(10.0, (int)log10(b)+1)+b;
}

int main() {


    int n;
    int t; cin >> t; t=0;
    memset(KMIN, 1, sizeof(KMIN));
    KMAX[0][0] = KMIN[0][0] = 0;
    for(int i=0; i<10; i++) {
        for(int j=W[i]; j<=100; j++) {
            for(int k=0; k<10; k++) {
                int kmin = KMIN[j-W[i]][k];
                int kmax = KMAX[j-W[i]][k];
                
                if (j==W[i]) {
                    KMIN[j][i] = min(KMIN[j][i], i);
                    KMAX[j][i] = min(KMAX[j][i], i);
                } else {
                    KMIN[j][i] = min(KMIN[j][i], min(prepend(kmin, i), prepend(i, kmin)));
                    KMAX[j][i] = max(KMAX[j][i], max(prepend(kmax, i), prepend(i, kmax)));
                }
            }
        }
    }
  
    while(cin >> n) {
        int minn = 0x01010101, maxx = 0;
        for(int i=1; i<10; i++) {
            minn = min(minn, KMIN[n][i]);
            maxx = max(maxx, KMAX[n][i]);
        }
        cout << minn << " " << maxx << endl;
    }

    return 0;
}
