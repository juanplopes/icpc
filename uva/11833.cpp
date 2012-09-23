//11833
//Route Change
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 252

using namespace std;

struct Edge {
    int v, c;
    Edge(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Edge& that) const { return c > that.c; }
};   

int G[MAX][MAX];
int V[MAX], S[MAX];
int n, m, cc, kk;

int main() {
    while(cin >> n >> m >> cc >> kk, n|m|cc|kk) {
        memset(V, 0x3f, sizeof(V));
        memset(S, 0, sizeof(S));
        memset(G, -1, sizeof(G));
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] = G[b][a] = c;
        }
       
        for(int i=cc-2; i>=0; i--) {
            S[i] = S[i+1] + G[i][i+1];
        }
       
        int totalc=0;

        priority_queue<Edge> Q;
        Q.push(Edge(kk, 0));

        while(totalc < n && !Q.empty()) {
            Edge item = Q.top(); Q.pop();
            if (item.c >= V[item.v]) continue;
            V[item.v] = item.c;
            totalc++;
            if (item.v < cc) continue;
            for(int j=0; j<n; j++) {
                if (G[item.v][j]>=0) {
                    Edge e = Edge(j, G[item.v][j]);
                    if (item.c + e.c < V[e.v])
                        Q.push(Edge(e.v, item.c + e.c));
                }
            }
        }
        
        int minn = 0x3f3f3f3f;
        for(int i=0;i<cc;i++) {
            minn = min(minn, V[i]+S[i]);
        }
        cout << minn << endl;
    }
    return 0;
}
