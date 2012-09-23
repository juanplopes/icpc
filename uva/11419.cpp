//11419
//SAM I AM
//Graphs;Bipartite Matching;Konig Theorem
#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#define MAX 2005
using namespace std;

string VA[MAX], VB[MAX];
int G[MAX][MAX], n, r, c, p;
vector<int> G2[MAX];
bool V[MAX];

inline int SOURCE() { return 0; }
inline int TARGET() { return 1; }
inline int R(int i) { return 1+i; }
inline int C(int i) { return 1+r+i; }

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    for(int i=0; i<G2[s].size(); i++) {
        int u = G2[s][i];
        if (!V[u] && G[s][u] > 0) {
            if (int sent = send(u, t, min(minn, G[s][u]))) {
                G[s][u] -= sent;
                G[u][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

void mark(int v, bool side) {
    V[v] = true;
    for(int i=0; i<G2[v].size(); i++) {
        int u = G2[v][i];
        if (!V[u] && (side && G[v][u] || !side && G[u][v]))
            mark(i, !side);        
    }
}


int main() {
    while(scanf("%d %d %d", &r, &c, &p), r|c|p) {
        memset(G, 0, sizeof(G));
        memset(G2, 0, sizeof(G2));
        memset(V, 0, sizeof(V));

        for(int i=1; i<=r; i++) {
            G[SOURCE()][R(i)] = 1;  
            G2[SOURCE()].push_back(R(i));
        }
        
        for(int i=1; i<=c; i++) {
            G[C(i)][TARGET()] = 1;  
            G2[C(i)].push_back(TARGET());
        }

        
        for(int i=0; i<p; i++) {
            int a, b;
            cin >> a >> b;
            G[R(a)][C(b)] = 1;
            G2[R(a)].push_back(C(b));
            G2[C(b)].push_back(R(a));
        }

        n = r+c+1;
        
        int total = 0;
        while(int sent = send(SOURCE(), TARGET(), INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        
        V[0] = V[1] = true;
        for(int i=1; i<=r; i++) {
            bool inflow = false;
            for(int j=1; j<=c; j++)
                inflow |= G[C(j)][R(i)];
            
            if (!V[R(i)] && !inflow)
                mark(R(i), true);            
        }
        printf("%d", total);        
        for(int i=1; i<=r; i++)
            if (!V[R(i)]) printf(" r%d", i);

        for(int i=1; i<=c; i++)
            if (V[C(i)]) printf(" c%d", i);

        printf("\n");
    }

    return 0;
}
