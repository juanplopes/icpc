//10243
//Fire! Fire! Fire!
//Graphs;DFS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 1005
using namespace std;

int n;
bool G[MAX][MAX];
bool L[MAX];
bool V[MAX];

void dfs(int v, bool start) {
    //cout << "*" << v << endl;
    if (V[v]) return;
    V[v] = true;
    bool all = true;
    int children = 0;
    for(int i=0;i<n;i++) {
        if (G[v][i] && !V[i]) {
            dfs(i, false);
            all &= L[i];
            children++;
        }
    } 
    if (!all && children > 0 || start && children==0)
        L[v] = true;
}

int main() {
    int a, b, m;
   
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(L, 0, sizeof(L));
        memset(V, 0, sizeof(V));
        
        for(int i=0;i<n;i++) {
            cin >> m;
            for(int j=0; j<m; j++) {
                cin >> a;
                a--;
                G[i][a] = G[a][i] = true;
            }
        }

        int count = 0;
        for(int i=0;i<n;i++) {
            dfs(i, true);
            if (L[i]) count++;
        }

        cout << count << endl;
    }
    
    
        
}
