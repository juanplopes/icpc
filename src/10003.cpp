//10003
//Cutting Sticks
//Dynamic Programming;Matrix Multiplication
#define MAX 1001
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int T[MAX][MAX], S[MAX], n;
bool V[MAX][MAX];

int TT(int a, int b) {
    if (a+1==b) return 0;
    if (V[a][b]) return T[a][b];

    int minn = INT_MAX;
    for(int i=a+1; i<b; i++)
        minn = min(minn, TT(a,i) + TT(i,b) + S[b]-S[a]);
    
    V[a][b] = true;
    return T[a][b] = minn;
}

int main() {
    int t;
    while(cin >> t, t) {
        cin >> n;
        
        memset(S, 0, sizeof(S));
        memset(V, 0, sizeof(V));
        S[0] = 0;
        for(int i=1; i<=n; i++) {
            cin >> S[i];
        }
        S[n+1] = t;
           
        cout << "The minimum cutting is " << TT(0, n+1) << "." << endl; 
        
    }    
}

