//11838
//Come and Go
//Graphs;Strongly Connected Components
#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

bool V[MAX];
int O[MAX], npv;
bool G[MAX][MAX];
int n, m;

void DFS(int v){
    V[v] = true;
    for(int i = 1; i <= n; i++)
        if (G[v][i] && !V[i])
            DFS(i);
    O[++npv] = v;
}

void DFSt(int v){
    V[v] = true;
    for(int i = 1; i <= n; i++)
       if (G[i][v] && !V[i])
            DFSt(i);
}


int main() {
    int a, b, t;
    while(cin >> n >> m, n|m) {
        memset(G, 0, sizeof(G));
        
        while(m--) {
            cin >> a >> b >> t;
            G[a][b] = true;
            if (t==2)
                G[b][a] = true;
        }
        
        npv = 0;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));

        for(int i = 1; i <= n; i++)
            if(!V[i]) DFS(i);

        memset(V, 0, sizeof(V));

        int comp = 0;
        for(int i = n; i > 0; i--)
            if(!V[O[i]]) {
                comp++;
                DFSt(O[i]);
            }

        cout << (comp==1) << endl;
    }

    return 0;
}
