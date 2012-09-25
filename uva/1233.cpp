//1233
//USHER
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cassert>
#define MAX 501

using namespace std;
 
int P[MAX];
int G[MAX][MAX];
int n, m;

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int b, p, q; cin >> b >> p >> q;
        for(int i=0; i<q; i++)
            cin >> P[i]; 

        memset(G, 0x1f, sizeof(G));

        G[0][0] = 0;
        for(int i=1; i<=p; i++) {
            int k; cin >> k;
            G[i][i] = 0;
            for(int j=0; j<k; j++) {
                int x, y; cin >> x >> y;
                G[i][y] = min(G[i][y], x);
            }
        }
        
        for(int k=0; k<=p; k++)
            for(int i=0; i<=p; i++)
                for(int j=0; j<=p; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
   
        int minn = 1<<30;
        for(int i=0; i<q; i++) {
            minn = min(minn, G[P[i]][0]);
        }

        int current = 0;
        int answer = 0;
        while(true) {
            if ((current += minn) >= b) break;
            current--;
            answer++;
        }
        
        cout << answer << endl;
    }
    return 0;
}
