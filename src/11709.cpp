//11709
//Trust Groups
//Graphs;Strongly Connected Components
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#define MAX 1001
using namespace std;

map<string, int> P;
int person(const string& p) {
    if (P.find(p) != P.end())
        return P[p];
    else
        return P[p] = P.size();
}

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
    int a, b, t; string p, q;
    while(cin >> n >> m, n|m) {
        memset(G, 0, sizeof(G));
        P.clear();
        getline(cin, p);

        for(int i=0; i<n; i++) getline(cin, p);
        
        while(m--) {
            getline(cin, p);
            getline(cin, q);
            G[person(p)][person(q)] = true;
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

        cout << comp << endl;
    }

    return 0;
}
