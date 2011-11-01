//12196
//Klingon Levels
//Misc;Ad hoc
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int T[10001][1001];
int N[10001];

inline long abs(long n) { return n>0?n:-n;}

int main() {
    int n, tmp;
    while(cin >> n, n) {
        memset(T, 0, n*sizeof(T[0]));
        for(int i=0; i<n; i++) {
            cin >> N[i];
            for(int j=0; j<N[i]; j++) {
                cin >> tmp;
                T[i][tmp]++;
            }
            for(int j=1;j<=1000;j++)
                T[i][j] += T[i][j-1];
        }
        
        long minn = INT_MAX;
        for(int t=0;t<=1000;t++) {
            long sum=0;
            for(int i=0; i<n; i++) {
                sum += abs(N[i] - 2*T[i][t]);
            }
            minn = min(minn, sum);
        }
        cout << minn << endl;
    }
}
