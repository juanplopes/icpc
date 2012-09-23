//1247
//Interstar Transport
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 30

using namespace std;

struct Edge {
    int u, v, c;
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
    inline bool operator < (const Edge& that) const { return c > that.c; }
};   

int G[MAX][MAX];
int V[MAX];
int D[MAX];
int n, m;

void show(int t) {
    if (D[t] != t) {
        show(D[t]);
        cout << " ";
    }
    
    cout << (char)(t+'A');
}

int shortest(int a, int b) {
    memset(V, 0x3f, sizeof(V));
    priority_queue<Edge> Q;
    Q.push(Edge(a, a, 0));

    while(!Q.empty()) {
        Edge item = Q.top(); Q.pop();
        if (item.c >= V[item.v]) continue;
        V[item.v] = item.c;
        D[item.v] = item.u;

        for(int j=0; j<n; j++) {
            if (G[item.v][j]) {
                Edge e = Edge(item.v, j, item.c+G[item.v][j]);
                if (e.c <= V[e.v])
                    Q.push(e);
            }
        }
    }
    show(b); cout << endl;
}

int main() {
    while(cin >> n >> m) {
        memset(G, 0, sizeof(G));
        
        for(int i=0; i<m; i++) {
            char a, b; int c;
            cin >> a >> b >> c;
            G[a-'A'][b-'A'] = G[b-'A'][a-'A'] = c;
        }

        int k; cin >> k;
        while(k--) {
            char a, b; cin >> a >> b;
            shortest(a-'A', b-'A');
        }
    }
    return 0;
}
