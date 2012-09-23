//1197
//The Suspects
//Graphs;DFS
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

vector<int> G[501], P[30001];
bool VG[501], VP[30001];
int n, m;

int dfs(int v) {
    int sum = 1;
    VP[v] = true;
        
    for(int i=0; i<P[v].size(); i++) {
        int g = P[v][i];
        if (VG[g]) continue;
        VG[g] = true;
        
        for(int j=0; j<G[g].size(); j++) {
            int u = G[g][j];
            if (VP[u]) continue;
            sum += dfs(u);
        }
    }
    
    return sum;
}

int main() {
    while(cin >> n >> m, n|m) {
        memset(G, 0, sizeof(G));
        memset(P, 0, sizeof(P));
        memset(VG, 0, sizeof(VG));
        memset(VP, 0, sizeof(VP));
        
        for(int i=0; i<m; i++) {
            int k; cin >> k;
            while(k--) {
                int a; cin >> a;
                G[i].push_back(a);
                P[a].push_back(i);
            }
        }
        
        cout << dfs(0) << endl;
    }
    return 0;
}
