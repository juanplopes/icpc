//10480
//Sabotage
//Graphs;Maximum Flow;Ford-Fulkerson
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#define MAX 1006
using namespace std;

int G[MAX][MAX], O[MAX][MAX], n, m;
bool V[MAX];

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    for(int i=1; i<=n; i++) {
        if (!V[i] && G[s][i] > 0) {
            if (int sent = send(i, t, min(minn, G[s][i]))) {
                G[s][i] -= sent;
                G[i][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

int main() {
    int tt=0;
    while(cin >> n >> m, n|m) {
        if (tt++) cout << endl;

        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));
        
        for(int i=0;i<m;i++) {
            int a, b, f;
            cin >> a >> b >> f;
            G[a][b] = G[b][a] += f;
            O[a][b] += f;
        }
        
        int total = 0;
        while(int sent = send(1, 2, INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (O[i][j] > 0 && V[i] != V[j])
                    cout << i << " " << j << endl;
            }        
        }
    }
}
