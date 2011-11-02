//11631
//Dark roads
//Graphs;Minimum Spanning Tree;Prim;Priority Queue
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 200010

using namespace std;

struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Road& that) const { return c > that.c; }
};   

vector<Road> G[MAX];
priority_queue<Road> Q;
int n, m;
bool V[MAX];


int main() {
    while(cin >> n >> m, n|m) {
        int before = 0;
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        Q = priority_queue<Road>();
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Road(b, c));
            G[b].push_back(Road(a, c));
            before += c;
        }
        
        int total = 0, totalc=0;

        Q.push(Road(0, 0));

        while(totalc < n) {
            Road item = Q.top(); Q.pop();
            if (V[item.v]) continue;
            
            V[item.v] = true;
            total += item.c;
            totalc++;
            
            for(int j=0; j<G[item.v].size(); j++)
                if (!V[G[item.v][j].v])
                    Q.push(G[item.v][j]);
        }
        
        cout << before-total << endl;
    }
    return 0;
}
