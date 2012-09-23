//12179
//Randomly-priced Tickets
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#define MAX 101
using namespace std;

int G[MAX][MAX], n, r, c;
double P[101][10001];

int main() {
    int t; cin >> t; t=0;
    cout << fixed << setprecision(6);

    while(cin >> n >> r) {
        memset(G, 0x3F, sizeof(G));
        memset(P, 0, sizeof(P));
        
        char cc;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> cc; 
                if (cc=='Y') G[i][j] = 1;
            }
        }

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        P[0][0] = 1;
        double pp = 1.0/r;
        for(int i=1; i<=100; i++)
            for(int k=1; k<=r; k++)
                for(int j=k; j<=100*r; j++)
                    P[i][j] += P[i-1][j-k] * pp;

        cout << "Case " << ++t << endl;
        cin >> c;
        while(c--) {
            int a, b, m; 
            cin >> a >> b >> m; 
            a--; b--;
            
            int d=G[a][b];
            
            double total = 0;
            for(int i=0; i<=m; i++)
                total += P[d][i];
            cout << total << endl;
        }
        cout << endl;
    }
    return 0;
}
