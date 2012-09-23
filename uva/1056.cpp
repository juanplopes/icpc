//1056
//Degrees of Separation
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cassert>
#define MAX 51

using namespace std;
 
int G[MAX][MAX];
int n, m;
map<string, int> M;
         
int person(string& s) { 
    if (M.find(s) != M.end())
        return M[s];
    else
        return M[s]=M.size();
       
}

int main() {
    int t=0;
    while(cin >> n >> m, n|m) {
        memset(G, 0x1f, sizeof(G));
        M.clear();
        
        for(int i=0; i<m; i++) {
            string p, q;
            cin >> p >> q;
            int a = person(p), b=person(q);
            G[a][b] = G[b][a] = 1;
        }
        for(int i=1; i<=n; i++) G[i][i] = 0;
        
        assert(M.size() <= n);
        
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
   
        int maxx = 0;
        for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++) 
                    maxx = max(maxx, G[i][j]);
                   
        cout << "Network " << ++t << ": ";
        
        if (maxx <= n)
            cout << maxx << endl;
        else
            cout << "DISCONNECTED" << endl;
        
        cout << endl;
        
        
    }
    return 0;
}
