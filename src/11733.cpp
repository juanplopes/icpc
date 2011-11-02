//11733
//Airports
//Graphs;Minimum Spanning Tree;Prim;Priority Queue
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10005

using namespace std;

struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Road& that) const { return c > that.c; }
};   

vector<Road> G[MAX];
int CStart[MAX], CCount[MAX], nc;
priority_queue<Road> Q;
int n, m, cca;
bool V[MAX];

int dfs(int v) {
    V[v] = true;
    int acum = 1;
    for(int i=0; i<G[v].size(); i++)
        if (!V[G[v][i].v])
            acum += dfs(G[v][i].v);
    return acum;
}

int main() {
    int t; cin >> t; t=0;
    while(cin >> n >> m >> cca) {
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        nc = 0;
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c<cca) {
                G[a].push_back(Road(b, c));
                G[b].push_back(Road(a, c));
            }
        }
         
        for(int i=1; i<=n; i++) {
            if (!V[i]) {
                CStart[nc]=i; 
                CCount[nc]=dfs(i);
                nc++;
            }
        }
        
        int total = nc*cca;

        for(int i=0; i<nc; i++) {
            int totalc = 0;
            Q = priority_queue<Road>();
            Q.push(Road(CStart[i], 0));
            memset(V, 0, sizeof(V));

            while(totalc < CCount[i]) {
                Road item = Q.top(); Q.pop();
                if (V[item.v]) continue;
                
                V[item.v] = true;
                total += item.c;
                totalc++;
                
                for(int j=0; j<G[item.v].size(); j++)
                    if (!V[G[item.v][j].v])
                        Q.push(G[item.v][j]);
            }
        }
        
        cout << "Case #" << ++t << ": " << total << " " << nc << endl;
    }
    return 0;
}
