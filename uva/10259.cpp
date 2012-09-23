//10259
//Hippity Hopscotch
//Graphs;DFS
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX 101
using namespace std;

int T[MAX][MAX], M[MAX][MAX], n, k;

int walk(int x, int y, int curr) {
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    if (T[x][y] <= curr) return 0;
    if (M[x][y] >= 0) return M[x][y];
    
    int maxx = 0;
    for(int i=1; i<=k; i++) {
        maxx = max(maxx, walk(x-i, y, T[x][y])+T[x][y]);
        maxx = max(maxx, walk(x+i, y, T[x][y])+T[x][y]);
        maxx = max(maxx, walk(x, y-i, T[x][y])+T[x][y]);
        maxx = max(maxx, walk(x, y+i, T[x][y])+T[x][y]);
    }
    return M[x][y] = maxx;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(M, -1, sizeof(M));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> T[i][j];
        
        cout << walk(0,0, -1) << endl;
        if (t) cout << endl;
    }
    
    return 0;
}
