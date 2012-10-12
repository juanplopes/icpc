//610
//Street Directions
//Graphs;Finding Bridges
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], n, m, gpe;

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    for(int i = 1; i <= n; i++) {
        if(G[v][i]) {
            if(!V[i]){
                dfs(v, i);
                L[v] = min(L[v], L[i]);
                if(L[i] <= V[v]) {
                    G[i][v] = 0;
                }
            } else if(i != u) { 
                L[v] = min(L[v], V[i]);
                G[i][v] = 0;
            }
        }
    }
}

int main() {
    int tt = 0;
    while(cin >> n >> m, n|m) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        gpe = 0;
        
        cout << ++tt << endl << endl;
        
        for(int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            G[a][b] = G[b][a] = 1;
        }
        
        for(int i=1; i<=n; i++)
            if (!V[i])
                dfs(i, i);
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if (G[i][j])
                    cout << i << " " << j <<endl;
        
        cout << "#" << endl;
    }
}
