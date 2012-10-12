//10199
//Tourist Guide
//Graphs;Finding Articulation Points
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], P[MAX], n, m, gpe;
map<string, int> S;
string SR[MAX];
vector<string> F;

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    for(int i = 1; i <= n; i++) {
        if(G[v][i]) {
            if(!V[i]){
                dfs(v, i);
                L[v] = min(L[v], L[i]);
                if(L[i] >= V[v]) 
                    P[v]++;
            } else if(i != u) { 
                L[v] = min(L[v], V[i]);
            }
        }
    }
}

int main() {
    int tt = 0;
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        memset(P, 0, sizeof(P));
        S.clear();
        F.clear();
        gpe = 0;
        
        for(int i=1; i<=n; i++) {
            string s; cin >> s;
            S[s] = i;
            SR[i] = s;
        }

        cin >> m;        
        for(int i=0; i<m; i++) {
            string s1, s2; cin >> s1 >> s2;
            int a = S[s1], b = S[s2];
            G[a][b] = G[b][a] = 1;
        }
        
        for(int i=1; i<=n; i++) {
            if (!V[i]) {
                dfs(i, i);
                P[i]--;
            }
        }
        
        for(int i=1; i<=n; i++)
            if (P[i]>0)
                F.push_back(SR[i]);

        sort(F.begin(), F.end());

        if (tt) cout << endl;
        
        cout << "City map #" << ++tt << ": " << F.size() << " camera(s) found" << endl;
        for(int i=0; i<F.size(); i++)
            cout << F[i] << endl;
    }
}
