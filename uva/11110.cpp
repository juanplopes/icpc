//11110
//Equidivisions
//Graphs;Flood Fill
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#define MAX 102
using namespace std;

int G[MAX][MAX];
int n;

int fill(int x, int y, int v) {
    if (G[x][y] != v) return 0;
    if (x<=0 || x>n || y<=0 || y>n) return 0;
    
    G[x][y] = -1;
    return 1 + 
        fill(x-1, y, v) + fill(x+1, y, v) + 
        fill(x, y-1, v) + fill(x, y+1, v);
}

int main() {
    while(cin >> n, n) {
        int a, b; string s;
        memset(G, 0, sizeof(G));
        
        getline(cin, s);
        for(int i=1;i<n;i++) {
            getline(cin, s);
            stringstream sin(s);
            while(sin >> a >> b)
                G[a][b] = i;
        }
        bool good = true;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (G[i][j] >= 0)
                    good &= fill(i,j, G[i][j]) == n;
            }
        }
        
        cout << (good?"good":"wrong") << endl;
        
    }
    return 0;
}
