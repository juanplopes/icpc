//908
//Re-connecting Computer Sites
//Graphs;Minimum Spanning Tree;Prim
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 200010

struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
    bool operator < (const Road& that) const { return c > that.c; }
};   

using namespace std;

vector<Road> G[MAX];

int main() {
    int n, k, m, t=0;
    while(cin >> n) {
        memset(G, 0, sizeof(G));
        
        int before = 0;
        for(int i=0; i<n-1; i++) {
            int a, b, c;  
            cin >> a >> b >> c;
            G[a].push_back(Road(b, c));      
            G[b].push_back(Road(a, c));      
            before += c;
        }
    
        int total=0;
        cin >> k;
        for(int i=0; i<k; i++) {
            int a, b, c;  
            cin >> a >> b >> c;
            
            int maxx = 0, maxv, side, counter;
            for(int j=0; j<G[a].size(); j++)
                if (G[a][j].c > maxx) {
                    maxx = G[a][j].c;
                    maxv = j;
                    side= a; counter = b;
                }

            for(int j=0; j<G[b].size(); j++)
                if (G[b][j].c > maxx) {
                    maxx = G[b][j].c;
                    maxv = j;
                    side= b; counter = a;
                }
            
            if (maxx <= c) continue;
            total = maxx-c;
            G[side][maxv].v = counter;
            G[side][maxv].c = c;
        }
    
        cin >> m;
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
        }
            
        if (t++) cout << endl;
        cout << before << endl << before-total << endl;
    }
    return 0;
}
