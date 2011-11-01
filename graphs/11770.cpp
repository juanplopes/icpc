//11770
//Lighting Away
//Graphs;Topological Sorting
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
using namespace std;

bool V[MAX];
int O[MAX], npv;
vector<int> G[MAX];
int n, m;

void DFS(int v){
    if (V[v]) return;
    V[v] = true;
    for(int i = 0; i < G[v].size(); i++)
        DFS(G[v][i]);
    O[++npv] = v;
}

void DFSt(int v){
    if (V[v]) return;
    V[v] = true;
    for(int i = 0; i < G[v].size(); i++)
        DFSt(G[v][i]);
}


int main() {
    int a, b;
    int t; cin >> t; t=0;
    while(cin >> n >> m) {
        memset(G, 0, sizeof(G));
        
        while(m--) {
            cin >> a >> b;
            G[a].push_back(b);
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

        cout << "Case " << ++t << ": " <<  comp << endl;
    }

    return 0;
}
