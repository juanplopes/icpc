//11518
//Dominos 2
//Graphs;Flood Fill
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10002
using namespace std;

vector<int> G[MAX];
bool V[MAX];
int n,m,l;

int dfs(int v) {
    if (V[v]) return 0;
    V[v] = true;
    int r = 1;
    for(int i=0;i<G[v].size(); i++)
        r+=dfs(G[v][i]);
    return r;
}

int main() {
    int t; cin >> t;
    while(cin >> n >> m >> l) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        int sum = 0;
        for(int i=0;i<l;i++) {
            int a;
            cin >> a;
            sum+=dfs(a);
        }
        
        cout << sum << endl;
        
    }
    return 0;
}
