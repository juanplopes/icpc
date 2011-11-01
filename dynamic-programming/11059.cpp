//11059
//Maximum Product
//Dynamic Programming;Maximum Sum Contiguous Subsequence
#include <iostream>
#include <climits>
#include <cmath>
#define MAX 1005
using namespace std;

int main() {
    long long n, a, t=0;
    while(cin >> n) {
        long long maxx=0, newneg=0, newpos=0, spos=1, sneg=1;
        bool valid = false;
        for(int i=0;i<n;i++) {
            cin >> a;
            if (spos*a>0) {
                valid = true;
                spos*=a;
            } else {
                newneg = spos*a;
                spos = 1;
            }

            
            if (sneg*a<0) {
                sneg*=a;
            } else  {
                if (sneg*a>0) valid = true;
                newpos = sneg*a;
                sneg = 1;
            }
            
            maxx = max(maxx, spos = max(spos, newpos));
            sneg = min(sneg, newneg);
            newpos = newneg = 0;
        }
        if (!valid) maxx = 0;
        cout << "Case #" << ++t << ": The maximum product is " << maxx << "." << endl;
        cout << endl;
    }
    
    return 0;
}
