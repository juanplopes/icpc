//11747
//Heavy Cycle Edges
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
vector<int> R;
int n, m;
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
    while(cin >> n >> m, n|m) {
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        nc = 0;
        R.clear();
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Road(b, c));
            G[b].push_back(Road(a, c));
        }
         
        for(int i=1; i<=n; i++) {
            if (!V[i]) {
                CStart[nc]=i; 
                CCount[nc]=dfs(i);
                nc++;
            }
        }
        
        for(int i=0; i<nc; i++) {
            int totalc=0;
            Q.push(Road(CStart[i], 0));
            memset(V, 0, sizeof(V));

            while(totalc < CCount[i]) {
                Road item = Q.top(); Q.pop();
                if (V[item.v]) { R.push_back(item.c); continue; }
                
                V[item.v] = true;
                totalc++;
                
                for(int j=0; j<G[item.v].size(); j++)
                    if (!V[G[item.v][j].v])
                        Q.push(G[item.v][j]);
            }
            while(!Q.empty()) {
                R.push_back(Q.top().c); 
                Q.pop();
            }
        }
        sort(R.begin(), R.end());
        if (R.size()==0) {
            cout << "forest" << endl;
        } else {
            cout << R[0];
            for(int i=1; i<R.size(); i++)
                cout << " " << R[i];
            cout << endl;
        }
    }
    return 0;
}
