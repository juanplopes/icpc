//10278
//Fire Station
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#define MAX 502
using namespace std;

int G[MAX][MAX], f, n;
bool F[MAX];

int main() {
    int t; cin >> t;
    string s;
    while(t--) {
        cin >> f >> n;
        memset(G, 0x3F, sizeof(G));
        memset(F, 0, sizeof(F));

        for(int i=0;i<f; i++) {
            int a; cin >> a; F[a] = true;
        }
        getline(cin, s);
        while(getline(cin, s), cin && s!="") {
            int a, b, c;
            stringstream inter(s);
            inter >> a >> b >> c;
            G[a][b] = G[b][a] = c;
        }
        
       
        for(int k=1; k<=n; k++) {
            G[k][k] = 0;
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        }
                    
        int minn = INT_MAX, minv;
        for(int i=1; i<=n; i++) {
            int maxx = 0;
            for(int j=1; j<=n; j++) {
                int nearest = INT_MAX;
                for(int k=1; k<=n; k++) {
                    if (!F[k] && k!=i) continue;
                    nearest = min(nearest, G[k][j]);
                }
                maxx = max(maxx, nearest);
            }
            if (maxx < minn) {
                minn = maxx;
                minv = i;
            }
        }
        cout << minv << endl;
        if (t) cout << endl;
    }
}
