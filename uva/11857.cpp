//11857
//Driving Range
//Graphs;Minimum Spanning Tree;Kruskal
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Edge {
    int x, y, v;
    inline bool operator <(const Edge& that) const {
        return this->v < that.v;
    }    
};

Edge E[1000005];
int P[1000005];

inline int findset(int v) {
    if (P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return -1;
    if (a>b) swap(a,b);
    P[b] = a;
    return a;
}

int main() {
    int n, m;
    while(cin >> n >> m, n||m) {
        for(int i=0; i<n; i++)
            P[i] = i;
        
        for(int i=0; i<m; i++)
            cin >> E[i].x >> E[i].y >> E[i].v;

        sort(E, E+m);
        
        int maxx=0, count=0;
        for(int i=0; i<m && count < n-1; i++) {
            if(unionset(E[i].x, E[i].y) != -1) {
                maxx = max(maxx, E[i].v);
                count++;
            }
        }
        if (count == n-1)
            cout << maxx << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
