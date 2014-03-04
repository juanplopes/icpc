//1529
//Max, the Mad
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#define MAX 15

using namespace std;

struct Edge {
    int v, t, c;
    Edge(int v, int t, int c) : v(v), t(t), c(c) {}
    inline bool operator < (const Edge& that) const { return c < that.c; }
};   

vector<Edge> G[MAX];
priority_queue<Edge> Q;
int n, m, s, t;
int V[MAX][60], P[MAX];

int main() {
    int n, m, k;
    while(scanf("%d %d %d", &n, &m, &k), n|m|k) {
        memset(V, 0x3f, sizeof(V));
        memset(G, 0, sizeof(G));
        Q = priority_queue<Edge>();
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Edge(b, 0, c));
            G[b].push_back(Edge(a, 0, c));
        }
        
        for(int i=1; i<=n; i++)
            cin >> P[i];
        
        Q.push(Edge(1, k, 0));

        while(!Q.empty()) {
            Edge item = Q.top(); Q.pop();
            
            for(int j=0; j<G[item.v].size(); j++) {
                Edge e = G[item.v][j];
                int tank = item.t - e.c;
                if (tank < 0) continue;
            
                for(int jj=0; jj<=k-tank; jj++) {
                    int newc = item.c + P[e.v]*jj;
                    if (newc < V[e.v][tank+jj]) {
                        V[e.v][tank+jj] = newc;
                        Q.push(Edge(e.v, tank+jj, newc));
                    }
                }
            }
        }


        int minn = 0x3f3f3f3f;
        for(int i=0; i<=k; i++) {
            minn = min(minn, V[n][i]);
        }
        
        cout << (minn<0x3f3f3f3f?minn:-1) << endl;
    }
}

