//314
//Robot
//Graphs;Shortest Path;BFS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
#define MAX 70
using namespace std;

int G[MAX][MAX], n, m, sx, sy, tx, ty;
bool V[MAX][MAX][4];
string dir;

struct Step {
    int x, y, d, v, p;
    Step() {}
    Step(int x, int y, int d, int v, int p) : x(x), y(y), d(d), v(v), p(p) {}
    Step left(int pp) {
        return Step(x, y, (d+3)%4, v+1, pp);
    }
    Step right(int pp) {
        return Step(x, y, (d+1)%4, v+1, pp);
    }
    bool canGo(int i) {
        return (d==0 && x-i>=1 && !G[x-i][y]) ||
               (d==1 && y+i<m-1 && !G[x][y+i]) ||
               (d==2 && x+i<n-1 && !G[x+i][y]) ||
               (d==3 && y-i>=1 && !G[x][y-i]);
    }    
    Step go(int pp, int i) {
        if (d==0) return Step(x-i, y, d, v+1, pp);
        if (d==1) return Step(x, y+i, d, v+1, pp);
        if (d==2) return Step(x+i, y, d, v+1, pp);
        if (d==3) return Step(x, y-i, d, v+1, pp);
    }
    
};

int main() {
    while(cin >> n >> m, n|m) {
        vector<Step> Q;
        
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        
        for(int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> G[i][j];
                
        n++; m++;
        for(int i=n-1;i>=0;i--)
            for (int j=m-1;j>=0;j--)
                if (G[i][j])
                    G[i+1][j] = G[i][j+1] = G[i+1][j+1] = 1;
                
        cin >> sx >> sy >> tx >> ty >> dir;
        if (dir=="north") Q.push_back(Step(sx, sy, 0, 0, -1));
        if (dir=="east") Q.push_back(Step(sx, sy, 1, 0, -1));
        if (dir=="south") Q.push_back(Step(sx, sy, 2, 0, -1));
        if (dir=="west") Q.push_back(Step(sx, sy, 3, 0, -1));
        
        int ptr = 0;
        while(ptr < Q.size()) {
            Step it = Q[ptr];
            if (it.x == tx && it.y == ty) {
                cout << it.v << endl;
                break;
            }
            
            if (V[it.x][it.y][it.d]) { ptr++; continue; }
            V[it.x][it.y][it.d] = true;
            
            Q.push_back(it.left(ptr));
            Q.push_back(it.right(ptr));
            for (int i=1; i<=3 && it.canGo(i); i++)
                Q.push_back(it.go(ptr, i));
                
            ptr++;
        }
        if (ptr == Q.size()) cout << -1 << endl;
    }
}
