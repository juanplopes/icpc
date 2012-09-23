//10891
//Game of Sum
//Dynamic Programming;Matrix Multiplication
#define MAX 101
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int T[MAX][MAX], S[MAX], n;
bool V[MAX][MAX];

int TT(int a, int b) {
    if (b<a) return 0;
    if (V[a][b]) return T[a][b];

    int maxx = INT_MIN;
    for(int i=a; i<=b; i++)
        maxx = max(maxx, S[b]-S[a-1] - TT(i+1,b));
    
    for(int i=b; i>=a; i--)
        maxx = max(maxx, S[b]-S[a-1] - TT(a,i-1));
    
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

