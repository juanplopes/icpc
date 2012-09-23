//11294
//Wedding
//Graphs;2-SAT
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define MAX 1000
using namespace std;

vector<int> G[MAX*2], T[MAX*2];
int O[MAX*2], V[MAX*2], npv, n;
char R[MAX*2];

int neg(int x) { 
    if (x>=n) return x-n;
    return x+n;
}

void set(int v, bool value) {
    if (R[v] != 0) return;
    R[v] = value ? 'w' : 'h';
    R[neg(v)] = value ? 'h': 'w';
    
    if (value)
        for(int i=0; i<G[v].size(); i++)
            set(G[v][i], true);
    else
        for(int i=0; i<G[neg(v)].size(); i++)
            set(G[neg(v)][i], true);
}

void DFS(int v){
    V[v] = 1;
    for(int i = 0; i < G[v].size(); i++)
        if (!V[G[v][i]])
            DFS(G[v][i]);
    O[npv++] = v;
}

void DFSt(int v, int comp){
    V[v] = comp;
    for(int i = 0; i < T[v].size(); i++)
       if (!V[T[v][i]])
            DFSt(T[v][i], comp);
}

int main() {
    int m;
    while(cin >> n >> m, n||m) {
        memset(G, 0, sizeof(G));
        memset(T, 0, sizeof(T));
        memset(R, 0, sizeof(R));

        for(int i=0;i<m; i++) {
            int a, b; char c, d;
            cin >> a >> c >> b >> d;
            if (c=='h') a=neg(a);
            if (d=='h') b=neg(b);
            
            G[neg(a)].push_back(b);
            G[neg(b)].push_back(a);
        }
        
        G[neg(0)].push_back(0);
        
        for(int i=0; i<2*n; i++)
            for(int j=0; j<G[i].size(); j++)
                T[G[i][j]].push_back(i);
        
        npv = 0;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));

        for(int i = 0; i < 2*n; i++)
            if(!V[i]) DFS(i);

        memset(V, 0, sizeof(V));

        int comp = 0;
        for(int i = 2*n-1; i >= 0; i--)
            if(!V[O[i]])
                DFSt(O[i], ++comp);

        bool result = true;
        for(int i=0; i<n; i++) {
            result &= V[i] != V[neg(i)];
        }

        if (!result) {
            cout << "bad luck" << endl;
            continue;
        }
    
        for(int i=1; i<=comp; i++) {
            for(int j=0; j<2*n; j++) {
                if (V[j] == i)
                    set(j, false);
            }
        }

        for(int i=1; i<n; i++) {
            if (i>1) cout << " ";
            cout << i << R[i];
        }
        cout << endl;
    }    
}
