//1265
//Tour Belt
//Graphs;Minimum Spanning Tree;Kruskal
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

struct Edge {
    int x, y, v;
    Edge() {}
    Edge(int x, int y, int v) : x(x), y(y), v(v) {}
    
    inline bool operator <(const Edge& that) const {
        return this->v > that.v;
    }    
};

Edge E[5006*2506];
int A[5006][5006], B[5006][5006];
int P[5002], C[5002];

inline int findset(int v) {
    if (P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return 0;
    if (a>b) swap(a,b);
    P[b] = a;
    C[a] += C[b];
    C[b] = 0;
    return a;
}

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n, m; cin >> n >> m;
        for(int i=1; i<=n; i++) {
            P[i] = i;
            C[i] = 1;    
            
            for(int j=1; j<=n; j++) {
                A[i][j] = 1<<29;
                B[i][j] = 0;
            }
        }
        
        for(int i=0; i<m; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            E[i] = Edge(x, y, v);
            
            A[x][y] = A[y][x] = B[x][y] = B[y][x] = v;
        }
            
        sort(E, E+m);
        
        int total = 0;
        for(int i=0; i<m; i++) {
            int x = findset(E[i].x), y = findset(E[i].y);
            if (x==y) continue;

            int a = unionset(x, y);
            
            int outside = 0, inside = 1<<29;            
            for(int j=1; j<=n; j++) {
                A[a][j] = A[j][a] = min(A[x][j], A[y][j]);
                B[a][j] = B[j][a] = max(B[x][j], B[y][j]);
                
                if (findset(a) == findset(j))
                    inside = min(inside, A[a][j]);
                else
                    outside = max(outside, B[a][j]);
            }
            
            if (inside > outside)
                total += C[a];
        }
        
        cout << total << endl;
        
    }
}
