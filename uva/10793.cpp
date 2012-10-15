//10793
//The Orc Attack
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <algorithm>
#define MAX 105
using namespace std;

int G[MAX][MAX];

int main() {
    int t; cin >> t;
    for(int tt=1; tt<=t; tt++) {
        int n, m; cin >> n >> m;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++)
                G[i][j] = 1<<29;
            G[i][i] = 0;
        }

        for(int i=0; i<m; i++) {
            int x, y, c; 
            cin >> x >> y >> c;
            G[x][y] = G[y][x] = min(G[x][y], c);
        }
        
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      
        int minn = 1<<29;
        for(int i=1; i<=n; i++)
            if (*min_element(G[i]+1, G[i]+6) == *max_element(G[i]+1, G[i]+6))
                minn = min(minn, *max_element(G[i]+1, G[i]+n+1));
        
        cout << "Map " << tt << ": ";
        if (minn < 1<<29)
            cout << minn << endl;
        else
            cout << -1 << endl;
    }    
}
