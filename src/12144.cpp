//12144
//Almost Shortest Path
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 501

using namespace std;

struct Edge {
    int u, v, c;
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
    inline bool operator < (const Edge& that) const { return c > that.c; }
};   

int G[MAX][MAX];
int V[MAX];
vector<int> D[MAX];
int n, m, s, t;

void remove(int t) {
    if (D[t].size() == 0 || t == D[t][0]) return;
    for(int i=0; i<D[t].size(); i++) {
        G[D[t][i]][t] = 0;
        remove(D[t][i]);
    }
}

int shortest() {
    memset(V, 0x3f, sizeof(V));
    memset(D, 0, sizeof(D));
    priority_queue<Edge> Q;
    Q.push(Edge(s, s, 0));

    while(!Q.empty()) {
        Edge item = Q.top(); Q.pop();
        if (item.c > V[item.v]) continue;
        V[item.v] = item.c;
        D[item.v].push_back(item.u);

        for(int j=0; j<n; j++) {
            if (G[item.v][j]) {
                Edge e = Edge(item.v, j, item.c+G[item.v][j]);
                if (e.c <= V[e.v])
                    Q.push(e);
            }
        }
    }
    remove(t);
    if (V[t] < 0x3f3f3f3f)
        return V[t];
    else
        return -1;
    
}

int main() {
    while(cin >> n >> m, n|m) {
        cin >> s >> t;
        memset(G, 0, sizeof(G));
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] = c;
        }

        shortest();
        cout << shortest() << endl;
    }
    return 0;
}
