//1246
//Find Terrorists
//Math;Sieve
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool P[100];
int T[10000001];
vector<int> W;

long long real_mod(long long a, long long b) {
    long long c = a%b;
    if (c<0) c+=b;
    return c;
}

int main() {
    int n, k; 
    
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for(int i=2; i<100; i++) {
        if (P[i]) {
            W.push_back(i);
            for(int j=i*i; j>=0 && j<100; j+=i)
                P[j] = false;
        }
    }
    
    int t; cin >> t; t=0;
    int a, b;
    while(cin >> a >> b) {
        memset(T, 0, sizeof(int)*(b-a+1));
        
        if (a==0) { T[0]-=2; T[1] -= 1; }
        if (a==1) { T[0]-=1; }
        
        for(long long i=2; i*i<=b; i++) {
            for(long long j=max(real_mod(i*i+i-a, i), i*i+i-a); j<=(b-a); j+=i) {
                T[j]+=2;
            }
            int tmp = i*i-a;
            if (tmp >= 0 && tmp <= (b-a))
                T[tmp]++;
        }
        
        int cnt=0;
        for(int i=0; i<=(b-a);i++) {
            if (P[T[i]+2]) {
                cout << (cnt++?" ":"") << i+a;
            }
        }
        if (!cnt) cout << -1;
        cout << endl;
    }

}
