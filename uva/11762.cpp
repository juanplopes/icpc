//11762
//Race to 1
//Math;Probability
#include <iostream>
#include <iomanip>
#define MAX 1000010
using namespace std;

int P[MAX], K[MAX], D[MAX][30];
double R[MAX];

int main() {
    for(int i=2; i<MAX; i++) {
        K[i] = K[i-1];

        if (P[i] > 0) continue;
        K[i]++;

        for(int j=i, k=1; j<MAX; j+=i, k++)
            D[j][P[j]++] = k;
    }

    R[1] = 0;
    for(int i=2; i<MAX; i++) {
        for(int j=0; j<P[i]; j++)
            R[i] += R[D[i][j]];

        R[i] /= P[i];
        R[i] += (double)K[i] / P[i];
    }
    
    int t; cin >> t;
    for(int tt = 1; tt<=t; tt++) {
        int a; cin >> a;
        cout << "Case " << tt << ": " << fixed << setprecision(10) << R[a] << endl;
    }
}
