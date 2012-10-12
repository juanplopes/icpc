//929
//Number Maze
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Edge {
    int x, y, c;
    Edge(int x, int y, int c) : x(x), y(y), c(c) {};
    inline bool operator <(const Edge& a) const {
        return c > a.c;
    }
};

int G[MAX][MAX], V[MAX][MAX];
int n, m;
priority_queue<Edge> Q;

void try_q(int x, int y, int c) {
    if (x <= 0 || x > n || y<=0 || y > m || c+G[x][y] >= V[x][y]) return;
    Q.push(Edge(x, y, c+G[x][y]));
}


int main() {
    int T; cin >> T;
    for(int tt=1; tt<=T; tt++) {
        memset(V, 0x7f, sizeof(V));
        Q = priority_queue<Edge>();

        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> G[i][j];

        Q.push(Edge(1, 1, G[1][1]));
        
        while(!Q.empty()) {
            Edge e = Q.top(); Q.pop();    
            if (V[e.x][e.y] <= e.c) continue;
            
            V[e.x][e.y] = e.c;
            
            if (e.x == n && e.y == m) break;
            
            try_q(e.x-1, e.y, e.c);
            try_q(e.x+1, e.y, e.c);
            try_q(e.x, e.y-1, e.c);
            try_q(e.x, e.y+1, e.c);
        }
        
        cout << V[n][m] << endl;
    }
}
