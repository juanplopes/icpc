//10304
//Optimal Binary Search Tree
//Dynamic Programming;Optimal Search Tree
#define MAX 252
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int T[MAX][MAX], S[MAX], n;
bool V[MAX][MAX];

int TT(int a, int b) {
    if (b < a) return 0;
    if (V[a][b]) return T[a][b];

    int minn = INT_MAX;
    for(int i=a; i<=b; i++)
        minn = min(minn, TT(a,i-1) + TT(i+1,b) + (S[b]-S[a-1])-(S[i]-S[i-1]));
    
    V[a][b] = true;
    return T[a][b] = minn;
}

int main() {
    while(cin >> n) {
        memset(V, 0, sizeof(V));
        S[0] = 0;
        for(int i=1; i<=n; i++) {
            cin >> S[i];
            S[i] += S[i-1];
        }
        
        cout << TT(1, n) << endl;
        
    }    
}

