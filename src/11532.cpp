//11532
//Simple Adjacency Maximization
//Misc;Binary Manipulation
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

long long T[51][51];

int main() {
    for(int i=1;i<=50;i++) {
        for(int j=0;i+j<=50;j++) {
            int p=i, q=j;
            long long n = 0L;
            if (p%2!=0 && p/2<q) {
                n = 1;
                p--;
            }
            
            for(;p>1;p-=2) {
                if (q>0)
                    n = (n<<3) | 5L;
                else
                    n = (n<<2) | 3L;
                q--;
            }
            
            if (p==1) n = (n<<1) | 1L;
            T[i][j] = n;
        }
    }
    
    
    int t, p, q;
    cin >> t;
    while(cin >> p >> q) {
        cout << T[p][q] << endl;
    }

    return 0;
}
