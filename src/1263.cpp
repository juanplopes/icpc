//1263
//Mines
//Graphs;Topological Sorting
#include <iostream>
#include <cstring>
#define MAX 2001
using namespace std;

int n;
bool V[MAX], G[MAX][MAX];
int X[MAX], Y[MAX], D[MAX], O[MAX], npv;

inline int abs(int a) {
    return a>0?a:-a;
}

void dfs(int v, bool sort){
    V[v] = true;
    for(int i = 1; i <= n; i++)
        if (G[v][i] && !V[i])
            dfs(i, sort);
    if (sort)
        O[++npv] = v;
}

int main() {
    int t; cin >> t; t=0;
    while(cin >> n) {
        memset(G, 0, sizeof(G));
        for(int i=1; i<=n; i++) {
            cin >> X[i] >> Y[i] >> D[i];
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int r = D[i]/2;
                if (abs(X[j]-X[i])<=r && abs(Y[j]-Y[i]) <=r && i!=j)
                    G[i][j] = true;
            }
        }

        npv = 0;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));

        for(int i = 1; i <= n; i++)
            if(!V[i]) dfs(i, true);

        memset(V, 0, sizeof(V));

        int comp = 0;
        for(int i = n; i > 0; i--)
            if(!V[O[i]]) {
                comp++;
                dfs(O[i], false);
            }

        cout << comp << endl;
    }

    return 0;
}
