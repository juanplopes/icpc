//820
//Internet Bandwidth
//Graphs;Maximum Flow;Ford-Fulkerson
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#define MAX 1006
using namespace std;

int G[MAX][MAX], n;
int F[MAX][MAX];
bool V[MAX];

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    
    for(int i=1; i<=n; i++) {
        int capacity = G[s][i]-F[s][i];
        if (!V[i] && G[s][i]-F[s][i] > 0) {
            if (int sent = send(i, t, min(minn, capacity))) {
                F[s][i] += sent;
                F[i][s] -= sent;
                return sent;
            }
        }
    }
    
    return 0;
}

int main() {
    int tt=0;
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(F, 0, sizeof(F));
        memset(V, 0, sizeof(V));
        
        tt++;
        int s, t, c;
        cin >> s >> t >> c;
        for(int i=0;i<c;i++) {
            int a, b, f;
            cin >> a >> b >> f;
            G[a][b] = G[b][a] += f;
        }
        
        int total = 0;
        while(int sent = send(s, t, INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        
        cout << "Network " << tt << endl;
        cout << "The bandwidth is " << total << "." <<  endl;
        cout << endl;
    }
    
    
        
}
