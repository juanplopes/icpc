//10389
//Subway
//Graphs;Shortest Path;Dijkstra
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
#include <cassert>
#define MAX 205
#define WALK 1
#define METRO 4

using namespace std;

struct Edge {
    int v; double c;
    Edge(int v, double c) : v(v), c(c) {}
    inline bool operator < (const Edge& that) const { return c > that.c; }
};   

vector<Edge> G[MAX];
double V[MAX];
double X[MAX], Y[MAX];
int n;


double dist(double ax, double ay, double bx, double by) {
    return sqrt(pow(ax-bx, 2.0) + pow(ay-by, 2.0))*60/10000;
}

int main() {
    int t; cin >> t; t=0;
    while(cin >> X[0] >> Y[0] >> X[1] >> Y[1]) {
        memset(G, 0, sizeof(G));

        G[0].push_back(Edge(1, dist(X[0], Y[0], X[1], Y[1])));
        G[1].push_back(Edge(0, dist(X[0], Y[0], X[1], Y[1])));
        
        n = 2;
        string s;
        getline(cin, s);
        while(getline(cin, s) && s!="" && s[0]!=' ') {
            stringstream sin(s);
            int mn=0;
            while(sin >> X[n] >> Y[n]) {
                if (X[n] == -1 && Y[n] == -1) {
                    assert(mn >= 2);
                    mn = 0;
                    break;
                }
                if (mn > 0) {
                    double mDist = dist(X[n-1], Y[n-1], X[n], Y[n])/METRO;
                    G[n-1].push_back(Edge(n, mDist));
                    G[n].push_back(Edge(n-1, mDist));
                }
                for(int i=0;i<n;i++) {
                    double aDist = dist(X[n], Y[n], X[i], Y[i])/WALK;
                    G[i].push_back(Edge(n, aDist));
                    G[n].push_back(Edge(i, aDist));
                }
                
                n++; mn++;
            }
            
        }
        
        int totalc=0;
        
        for(int i=0; i<n; i++) V[i] = -1;
        
        priority_queue<Edge> Q;
        Q.push(Edge(0, 0));

        while(totalc < n && !Q.empty()) {
            Edge item = Q.top(); Q.pop();
            if (item.c >= V[item.v] && V[item.v] >= 0) continue;
            
            V[item.v] = item.c;
            totalc++;
            
            for(int j=0; j<G[item.v].size(); j++) {
                Edge e = G[item.v][j];
                if (item.c + e.c < V[e.v] || V[e.v] == -1)
                    Q.push(Edge(e.v, item.c + e.c));
            }
        }
        
        if (t++) cout << endl;
        cout << (int)round(V[1]) << endl;
    }
    return 0;
}
