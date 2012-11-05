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

int V[MAX], L[MAX], P[MAX], n, gpe;
vector<int> G[MAX];

inline int findset(int v) {
    if (P[v] != -1 && P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    P[b] = a;
}

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i];
        if(!V[w]){
            dfs(v, w);
            L[v] = min(L[v], L[w]);

            if (L[w] > V[v]) 
                unionset(v, w);
        } else if(w != u) { 
            L[v] = min(L[v], V[w]);
        }
    }
}

int main() {
    int m, q;
    while(cin >> n >> m >> q, n|m|q) {
        memset(G, 0, sizeof(vector<int>)*(n+1));
        memset(V, 0, sizeof(int)*(n+1));
        memset(L, 0, sizeof(int)*(n+1));
        memset(P, -1, sizeof(int)*(n+1));
        gpe = 0;

        for(int i=0; i<m; i++) {
            int a, b; 
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for(int i=0; i<n; i++)
            if (!V[i])
                dfs(i, i);

        for(int i=0; i<q; i++) {
            int a, b; 
            cin >> a >> b;
            cout << (findset(a)==findset(b) ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
    }
}
