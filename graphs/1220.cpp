#include <iostream>
#include <string>
#include <map>
#include <cstring>
#define MAX 205
using namespace std;

map<string, int> E;
int emp(string& s) {
    if (E.find(s) != E.end())
        return E[s];
    else
        return E[s] = E.size()-1;
}

bool L[MAX], V[MAX], L2[MAX];
int G[MAX];
int n;

int dfs(int v) {
    int acum = 0, illu = 0, children = 0;
    for(int i=0;i<n;i++) {
        if (G[i] == v) {
            acum += dfs(i);
            if (L[i]) illu++;
            children++;
        }
    } 
    if (illu < children && children > 0)
        L[v] = true;
    return acum + L[v];
}

int main()
{
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        E.clear();
        string a, b;        
        cin >> a;
        G[emp(a)] = -1;
        for(int i=1;i<n;i++) {
            cin >> a >> b;   
            G[emp(a)] = emp(b);
        }
        
        int total = dfs(0);
        
        memcpy(L2, L, sizeof(L));
        bool unique = true;
        for(int i=0; i<n; i++) {
            if (!L2[i]) {
                memset(L, 0, sizeof(L));
                L[i] = true;
                if (dfs(0) == total)
                    unique = false;
            }
        }
        
        cout << n-total << " " << (unique?"Yes":"No") << endl;
    }
    return 0;
}
