//10986
//Sending email
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 200010

using namespace std;

struct Edge {
    int v, c;
    Edge(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Edge& that) const { return c > that.c; }
};   

vector<Edge> G[MAX];
priority_queue<Edge> Q;
int n, m, s, t;
int V[MAX];


int main() {
    int tt; cin >> tt; tt=0;
    while(cin >> n >> m >> s >> t) {
        int before = 0;
        memset(V, 0x3f, sizeof(V));
        memset(G, 0, sizeof(G));
        Q = priority_queue<Edge>();
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Edge(b, c));
            G[b].push_back(Edge(a, c));
            before += c;
        }
        
        int totalc=0;

        Q.push(Edge(s, 0));

        while(totalc < n && !Q.empty()) {
            Edge item = Q.top(); Q.pop();
            if (item.c >= V[item.v]) continue;
            
            V[item.v] = item.c;
            totalc++;
            
            for(int j=0; j<G[item.v].size(); j++) {
                Edge e = G[item.v][j];
                if (item.c + e.c < V[e.v])
                    Q.push(Edge(e.v, item.c + e.c));
            }
        }
        
        cout << "Case #" << ++tt << ": "; 
        if (V[t] < 0x3f3f3f3f)
            cout << V[t] << endl;
        else
            cout << "unreachable" << endl;
    }
    return 0;
}
