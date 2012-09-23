//11686
//Pick up Sticks
//Graphs;Topological Sorting
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 1000001
using namespace std;

int V[MAX];
int O[MAX], npv;
vector<int> G[MAX];
int n, m;

bool DFS(int d, int v){
    V[v] = 1;
    
    for(int i=0;i<G[v].size(); i++) {
        int u = G[v][i];
        if (V[u] == 1) return false;
        if (!V[u] && !DFS(d, u)) return false;
    }  
    O[++npv] = v;
    V[v] = 2;
    return true;
}


int main() {
    int a, b;
    while(scanf("%d%d",&n, &m), n|m) {
        for(int i=1;i<=n;i++) G[i].clear();
        npv = 0;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));
        
        while(m--) {
            scanf("%d%d",&a, &b);
            G[a].push_back(b);
        }
        

        bool ok = true;
        int d = 0;
        for(int i = 1; i <= n; i++)
            if (!V[i])
                ok &= DFS(++d, i);

        if (ok)
            for(int i = n; i > 0; i--)
                printf("%d\n", O[i]);
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
