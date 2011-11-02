//1174
//IP-TV
//Graphs;Minimum Spanning Tree;Prim;Priority Queue
#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
map<string, int> M;
         
int city(string& s) {
    if (M.find(s) != M.end())
        return M[s];
    else
        return M[s]=M.size();
       
}

int main() {
    int t; cin >> t; t=0;
    
    while(cin >> n >> m) {
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        M.clear();
        Q = priority_queue<Road>();
        
        for(int i=0; i<m; i++) {
            string p, q; int a, b, c;
            cin >> p >> q >> c;
            a = city(p); b=city(q);
            G[a].push_back(Road(b, c));
            G[b].push_back(Road(a, c));
        }
        
        int total = 0, totalc=0;

        Q.push(Road(1, 0));

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
        
        if (t++) cout << endl;
        cout << total << endl;
    }
    return 0;
}
