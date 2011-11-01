//1220
//Party at Hali-Bula
//Graphs;DFS
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#define MAX 205
using namespace std;

map<string, int> E;
int emp(string& s) {
    if (E.find(s) != E.end())
        return E[s];
    else
        return E[s] = E.size()-1;
}

bool L[MAX], L2[MAX];
vector<int> G[MAX];
int n;

int dfs(int v) {
    int acum = 0, illu = 0;
    for(int i=0;i<G[v].size();i++) {
        acum += dfs(G[v][i]);
        if (L[G[v][i]]) illu++;
    } 
    if (G[v].size() > 0 && illu < G[v].size())
        L[v] = true;
    return acum + L[v];
}

int main()
{
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(L, 0, sizeof(L));
        E.clear();
        string a, b;        
        cin >> a;
        emp(a);
        for(int i=1;i<n;i++) {
            cin >> a >> b;   
            G[emp(b)].push_back(emp(a));
        }
        
        int total = dfs(0);
        
        memcpy(L2, L, sizeof(L));
        bool unique = true;
        for(int i=0; i<n; i++) {
            if (!L2[i]) {
                memset(L, 0, sizeof(L));
                L[i] = true;
                if (dfs(0) == total) {
                    unique = false; 
                    break;
                }
            }
        }
        
        cout << n-total << " " << (unique?"Yes":"No") << endl;
    }
    return 0;
}
