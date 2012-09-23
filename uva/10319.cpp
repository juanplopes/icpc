//10319
//Manhattan
//Graphs;2-SAT
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define MAX 1000
using namespace std;

vector<int> G[MAX*2], T[MAX*2];
int O[MAX*2], V[MAX*2], npv, n, s, a;

int neg(int x) { 
    if (x>=n) return x-n;
    return x+n;
}

int av(int x) {
    return s+x;    
}

int st(int x) {
    return x;    
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
    int tt; cin >> tt;
    while(tt--) {
        cin >> s >> a >> m;
        n = (s+a);

        for(int i=0;i<2*n; i++) {
            G[i].clear();
            T[i].clear();
        }
    
        for(int i=0; i<m; i++) {
            int s1, a1, s2, a2;
            cin >> s1 >> a1 >> s2 >> a2;
            s1--; a1--; s2--; a2--;
            
            s1 = st(s1); s2=st(s2);
            a1 = av(a1); a2=av(a2);
            
            if (a1 == a2 && s1 == s2)
                continue;
            
            if (a2<a1) {
                s1 = neg(s1);
                s2 = neg(s2);
            } 
            
            if (s2<s1) {
                a1 = neg(a1);
                a2 = neg(a2);
            }
            
            if (a1 == a2) {
                G[neg(a1)].push_back(a1);
                continue;           
            }
            
            if (s1 == s2) {
                G[neg(s1)].push_back(s1);
                continue;           
            }
               
            G[neg(s1)].push_back(a1);
            G[neg(a1)].push_back(s1);

            G[neg(s1)].push_back(s2);
            G[neg(s2)].push_back(s1);

            G[neg(a2)].push_back(a1);
            G[neg(a1)].push_back(a2);

            G[neg(a2)].push_back(s2);
            G[neg(s2)].push_back(a2);
        }
        
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

        cout << (result ? "Yes" : "No") << endl;
    }    
}
