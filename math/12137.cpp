#include <iostream>
#include <vector>
#include <cstring>
#define ull unsigned long long
#define MAX 1000001
using namespace std;

bool P[MAX];
int T[MAX];
vector<int> W;

ull pow(ull a, ull b) {
    if (b==0) return 1;
    ull tmp = b%2 ? a : 1;
    ull r = pow(a, b/2);
    return tmp*r*r;
}

int main() {
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for(ull i=2; i<MAX; i++) {
        if (P[i]) {
            W.push_back(i);
            for(ull j=i*i; j<MAX; j+=i)
                P[j] = false;
        }
    }
    ull n, t=0;
    while(cin >> n, n) {
        memset(T, 0, sizeof(T));
        
        int p = 0;
        ull fn = n;
        while(fn>1 && p<W.size()) {
            ull temp = fn/W[p];
            if (temp*W[p]==fn) {
                T[p]++;
                fn = temp;
            } else {
                p++;
            }
        }

        ull step = fn;
        for(int i=0;i<=p; i++) {
            if (T[i])
                step *= (ull)pow(W[i], (T[i]+1)/2);
        }
        
        ull result = n/step;
        if (n%step==0) result--;
        result *= 8;
        
        cout << "Case " << ++t << ": ";
        if(result)
            cout << result << endl;
        else
            cout << "Impossible" << endl;
    }
}
