//10397
//Connect the Campus
//Graphs;Minimum Spanning Tree;Prim;Priority Queue
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#define MAX 200010

using namespace std;

struct Road {
    int v; double c;
    Road(int v, double c) : v(v), c(c) {}
    inline bool operator < (const Road& that) const { return c > that.c; }
};   


vector<Road> G[MAX];
int X[MAX], Y[MAX];
priority_queue<Road> Q;
int n, m;
bool V[MAX];


int main() {
    while(cin >> n) {
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        Q = priority_queue<Road>();
        
        for(int i=1; i<=n; i++) {
            int x, y;
            cin >> x >> y;
            X[i] = x; Y[i] = y;
            for(int j=1; j<=i; j++) {
                double d = sqrt(pow(X[i]-X[j], 2.0)+pow(Y[i]-Y[j], 2.0));
                G[i].push_back(Road(j, d));
                G[j].push_back(Road(i, d));
            }
        }
        
        cin >> m;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(Road(b, 0));
            G[b].push_back(Road(a, 0));
        }
        
        double total = 0; int totalc=0;
        Q.push(Road(1,0));

        while(totalc < n && !Q.empty()) {
            Road item = Q.top(); Q.pop();
            if (V[item.v]) continue;
            
            V[item.v] = true;
            total += item.c;
            totalc++;
            
            for(int j=0; j<G[item.v].size(); j++)
                if (!V[G[item.v][j].v])
                    Q.push(G[item.v][j]);
        }
        
        cout << setprecision(2);
        cout << fixed << total << endl;
    }
    return 0;
}
