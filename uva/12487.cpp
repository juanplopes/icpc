//12487
//Midnight Cowboy
//Graphs;Markov Chain
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#define ull unsigned long long;
using namespace std;

double G[101][101], G2[101][101];
int S[101];

int main() {
    int n, a, b, c;
    while(cin >> n >> a >> b >> c) {
        memset(S, 0, sizeof(S));
        memset(G, 0, sizeof(G));
        
        for(int i=0;i<n-1;i++) {
            int x, y; cin >> x >> y;
            G[x][y] = G[y][x] = 1;
            S[x]++;
            S[y]++;
        }
        for(int i=1; i<=n; i++) {
            G[b][i] = G[c][i] = 0;
        }
        G[b][b] = G[c][c] = S[b] = S[c] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                G[i][j] /= S[i];
               // cout << " " << G[i][j];
            }
            //cout << endl;
        }
        
        for(int p=0; p<20; p++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    G2[i][j] = 0;
                    for(int k=1; k<=n; k++) {
                        G2[i][j] += G[i][k] * G[k][j]; 
                    }
                }
            }
            swap(G, G2);
        }
            /* cout << "--" << endl;
               for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
               // G[i][j] /= S[i];
                cout << " " << G[i][j];
            }
            cout << endl;
        }*/
                
        cout << fixed << setprecision(6) << G[a][b] / (G[a][b] + G[a][c]) << endl;
    }
}
