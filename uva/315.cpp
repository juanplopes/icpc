//315
//Network
//Graphs;Finding Articulation Points
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#define MAX 101
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], P[MAX], n, gpe;

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    for(int i = 1; i <= n; i++) {
        if(G[v][i]) {
            if(!V[i]){
                dfs(v, i);
                L[v] = min(L[v], L[i]);
                if(L[i] >= V[v]) P[v]++;
            } else if(i != u) { 
                L[v] = min(L[v], V[i]);
            }
        }
    }
}

int main() {
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        memset(P, 0, sizeof(P));
        gpe = 0;
        
        int a, b; string s;
        while(getline(cin, s), s != "0") {
            stringstream sin(s);
            sin >> a;
            while(sin >> b) {
                G[a][b] = G[b][a] = 1;
            }
        }
        dfs(1, 1); P[1]--;
        int cnt = 0;
        for(int i=1; i<=n; i++)
            if (P[i]) cnt++;
        
        cout << cnt << endl;
    }
}
