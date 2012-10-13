//11280
//Flying to Fredericton
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Edge {
    int v, c, s;
    Edge(int v, int c, int s) : v(v), c(c), s(s) {}
    inline bool operator <(const Edge& a) const {
        return this->c > a.c;
    }
};

vector<Edge> G[MAX];
int V[MAX][MAX];
map<string, int> S;
int n, m;

int main() {
    int T; cin >> T;
    for(int tt=1; tt<=T; tt++) {
        S.clear();
        memset(G, 0, sizeof(G));
        memset(V, 0x7f, sizeof(V));

        cin >> n;
        for(int i=1; i<=n; i++) {
            string s; cin >> s;
            S[s] = i;
        }
        
        cin >> m;
        for(int i=1; i<=m; i++) {
            string s1, s2; 
            int cost;
            cin >> s1 >> s2 >> cost;

            G[S[s1]].push_back(Edge(S[s2], cost, 0));
        }       
        
        priority_queue<Edge> Q;
        Q.push(Edge(1, 0, 0));
        
        while(!Q.empty()) {
            Edge e = Q.top(); Q.pop();    
            if (V[e.v][e.s] < e.c) continue;
            
            V[e.v][e.s] = e.c;
            
            for(int i=0; i<G[e.v].size(); i++) {
                Edge a = G[e.v][i];
                Q.push(Edge(a.v, e.c+a.c, e.s+1));
            }
        }
        
        if (tt>1) cout << endl;
        cout << "Scenario #" << tt << endl;
        int q; cin >> q;
        for(int i=0; i<q; i++) {
            int a; cin >> a;
            int minn = 0x7f7f7f7f;
            for(int j=0; j<=a+1; j++) {
                minn = min(minn, V[n][j]);
            }
            
            if (minn < 0x7f7f7f7f)
                cout << "Total cost of flight(s) is $" << minn << endl;
            else
                cout << "No satisfactory flights" << endl;
        }

    }
}
