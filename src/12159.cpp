//12159
//Gun Fight
//Graphs;Bipartite Matching
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
#include <vector>
#include <cassert>
#define MAX 306
using namespace std;

int X[MAX], Y[MAX], P[MAX], G[MAX][MAX], n, r, a, b;
bool V[MAX];

bool team(int c) {
    return (X[b] - X[a])*(Y[c] - Y[a]) - (Y[b] - Y[a])*(X[c] - X[a]) > 0;
}

int sqrdist(int a, int b) {
    return (X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b]);
}

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
    int t=0;
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        
        for(int i=1;i<=n;i++)
            cin >> X[i] >> Y[i] >> P[i];
        cin >> a >> b >> r;
        
        vector<int> A, B;
        for(int i=1;i<=n;i++) {
            if (P[i] == 0) continue;
            if (team(i)) 
                B.push_back(i);
            else      
                A.push_back(i);
        }
        if (A.size() > B.size()) A.swap(B);
        
        for(int i=0; i<A.size(); i++) {
            int u=A[i];
            G[0][u] = 1;
            for(int j=0; j<B.size(); j++) {
                int v = B[j];
                G[v][n+1] = 1;
                if (sqrdist(u, v) <= r*r && P[u] > P[v]) 
                    G[u][v] = 1;
            }
        }
        n++;
        
        memset(V, 0, sizeof(V));
        int total = 0;
        while(int sent = send(0, n, INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        cout << "Case " << ++t << ": " << total << endl;
    }
}
