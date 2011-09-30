#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

int T[101][101], S[101], n;
bool V[101][101];

int TT(int a, int b) {
    if (V[a][b]) return T[a][b];

    int total = S[b]-S[a-1];
    
    if (a==b) return total;
    if (b<a) return 0;
    
    int maxx = INT_MIN;
    for(int i=a; i<=b; i++)
        maxx = max(maxx, total - TT(i+1,b));
    
    for(int i=b; i>=a; i--)
        maxx = max(maxx, total - TT(a,i-1));
    
    V[a][b] = true;
    return T[a][b] = maxx;
}

int main() {
    while(cin >> n, n) {
        memset(S, 0, sizeof(S));
        memset(V, 0, sizeof(V));
        S[0] = 0;
        for(int i=1; i<=n; i++) {
            cin >> S[i];
            S[i] += S[i-1];
        }
           
        cout << 2*TT(1, n)-S[n]-S[0] << endl; 
        
    }    
}
