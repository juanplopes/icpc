//12363
//Hedge Mazes
//Graphs;Finding Bridges
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int V[MAX], L[MAX], n, gpe;
vector<int> G[MAX], T[MAX];

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i];
        if(!V[w]){
            dfs(v, w);
            L[v] = min(L[v], L[w]);

            if (L[w] > V[v]) {
                T[w].push_back(v);
                T[v].push_back(w);
            }
        } else if(w != u) { 
            L[v] = min(L[v], V[w]);
        }
    }
}

void dfs2(int comp, int v) {
    V[v] = comp;

    for(int i = 0; i < T[v].size(); i++) {
        int w = T[v][i];
        if(!V[w])
            dfs2(comp, w);    
    }
}

int main() {
    int m, q;
    while(cin >> n >> m >> q, n|m|q) {
        memset(G, 0, sizeof(vector<int>)*n);
        memset(T, 0, sizeof(vector<int>)*n);
        memset(V, 0, sizeof(int)*n);
        memset(L, 0, sizeof(int)*n);
        gpe = 0;

        for(int i=0; i<m; i++) {
            int a, b; 
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for(int i=0; i<n; i++)
            if (!V[i])
                dfs(i, i);

        memset(V, 0, sizeof(int)*n);
        for(int i=0; i<n; i++)
            if (!V[i])
                dfs2(i+1, i);

        for(int i=0; i<q; i++) {
            int a, b; 
            cin >> a >> b;
            a--;b--;
            cout << (V[a]==V[b] ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
    }
}
