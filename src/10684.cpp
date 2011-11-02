//10684
//The Jackpot
//Dynamic Programming;Maximum Sum Contiguous Subsequence
#include <iostream>
#include <cmath>
#define MAX 1005
using namespace std;

int main() {
    int n, a;
    while(cin >> n, n) {
        int t=0, s=0;
        for(int i=0;i<n;i++) {
            cin >> a;
            if (s+a>=0)
                t = max(t, s+=a);
            else
                s = 0;
        }
        if (s>0) {
            cout << "The maximum winning streak is " << t << "." << endl;
        } else {
            cout << "Losing streak." << endl;
        }
    }
    
    return 0;
}
