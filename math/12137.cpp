#include <iostream>
#include <vector>
#include <cstring>
#define ull unsigned long long
#define MAX 1000001
using namespace std;

bool P[MAX];
vector<int> W;

ull pow(ull a, int b) {
    if (b==0) return 1;
    ull tmp = b&1 ? a : 1;
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
        ull ncopy = n;
        ull step = 1;
        for(int i=0; ncopy>1 && i<W.size(); i++) {
            int power=0;
            while(ncopy%W[i]==0) {
                ncopy/=W[i];
                power++;
            }
            step *= pow(W[i], (power+1)/2);
        }
        step *= ncopy;
        
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
