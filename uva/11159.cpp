//11159
//Factors and Multiples
//Graphs;Bipartite Matching
#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#define MAX 205
using namespace std;

int A[MAX], B[MAX], G[MAX][MAX], n;
bool V[MAX];

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    for(int i=0; i<=n; i++) {
        if (!V[i] && G[s][i] > 0) {
            if (int sent = send(i, t, min(minn, G[s][i]))) {
                G[s][i] -= sent;
                G[i][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

int main() {
    int t; cin >> t;

    for(int tt=1; tt<=t; tt++) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));

        int a; cin >> a;
        for(int i=1; i<=a; i++)
            cin >> A[i];
            
        int b; cin >> b;
        for(int i=1; i<=b; i++)
            cin >> B[i];
            
        for(int i=1; i<=a; i++) {
            G[0][i] = 1;
            for(int j=1; j<=b; j++)
                if (B[j]==0 || A[i] != 0 && B[j]%A[i] == 0)
                    G[i][a+j] = 1;
        }

        for(int i=a+1; i<=a+b; i++)
            G[i][a+b+1] = 1;

        n = a+b+1;
 
        int total = 0;
        while(int sent = send(0, n, INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        cout << "Case " << tt << ": " << total << endl;
    }

    return 0;
}
