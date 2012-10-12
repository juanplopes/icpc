//796
//Critical Links
//Graphs;Finding Bridges
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], n, gpe;

struct Ponte {
    int a, b;
    Ponte() { }
    Ponte(int a, int b) : a(min(a, b)), b(max(a, b)) {}
};
bool comp(const Ponte& a, const Ponte& b) { return a.a < b.a || (a.a==b.a && a.b < b.b); }
vector<Ponte> P;

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    for(int i = 0; i < n; i++) {
        if(G[v][i]) {
            if(!V[i]){
                dfs(v, i);
                L[v] = min(L[v], L[i]);
                if(L[i] > V[v]) P.push_back(Ponte(v, i));
            } else if(i != u) { 
                L[v] = min(L[v], V[i]);
            }
        }
    }
}

int main() {
    while(cin >> n) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        P.clear();
        gpe = 0;
        
        int a, an, b; char skip;
        for(int i=0; i<n; i++) {
            cin >> a >> skip >> an >> skip;
            while(an--) {
                cin >> b; G[b][a] = G[a][b] = 1;
            }
        }
        
        for(int i=0; i<n; i++)
            if (!V[i])
                dfs(i, i);

        cout << P.size() << " critical links" << endl;
        sort(P.begin(), P.end(), comp);
        
        for(int i=0;i<P.size(); i++) {
            cout << P[i].a << " - " << P[i].b << endl;
        }
        cout << endl;
    }
}
