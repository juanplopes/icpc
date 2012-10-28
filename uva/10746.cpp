//10746
//Crime Wave - The Sequel
//Graphs;Maximum Flow;Min Cost;Cycle Canceling
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 100
using namespace std;

double C[MAX][MAX], M[MAX];
int F[MAX][MAX], G[MAX][MAX], P[MAX], n, a, b;
bool V[MAX];

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    
    for(int i=0; i<n; i++) {
        if (!V[i] && G[s][i]-F[s][i]) {
            if (int sent = send(i, t, min(minn, G[s][i]-F[s][i]))) {
                F[s][i] += sent;
                F[i][s] -= sent;
                return sent;
            }
        }
    }
    
    return 0;
}

bool cancel_cycle(int source) {
    memset(M, 0x1f, sizeof M);
    M[source] = 0;

    bool cycle = false;
    int v;

    for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        if (G[i][j]-F[i][j] && M[i]+C[i][j]<M[j]) {
            cycle = k+1==n;
            v = i;
            
            M[j] = M[i] + C[i][j];
            P[j] = i;
        }

    if (not cycle) return false;
    
    for(int k=0; k<n; k++)
        v = P[v];
    
    int i=v, minn=1<<29;
    
    do {
        minn = min(minn, G[P[i]][i] - F[P[i]][i]);
    } while (i = P[i], i!=v);

    do {
        F[P[i]][i] += minn;
        F[i][P[i]] -= minn;
    } while (i = P[i], i!=v);

    return true;
}

int cruiser(int x) { return x; }
int bank(int x) { return b+x; }
int source() { return a+b; }
int target() { return a+b+1; }

int main() {
    while(cin >> a >> b, a|b) {
        memset(G, 0, sizeof(G));
        memset(F, 0, sizeof(F));
        memset(C, 0, sizeof(C));
 
        for(int i=0; i<a; i++)
            G[bank(i)][target()] = 1;

        for(int i=0; i<b; i++)
            G[source()][cruiser(i)] = 1;

        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                int cr = cruiser(j), bk = bank(i);
                cin >> C[cr][bk];
                G[cr][bk] = 1;
                C[bk][cr] = -C[cr][bk];
            }
        }
        
        n = target()+1;
        
        int total = 0, sent;
        while(memset(V, 0, sizeof V), sent = send(source(), target(), 1<<29))
            total += sent;

        while(cancel_cycle(source()));

        double cost = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if (F[i][j] > 0)
                    cost += F[i][j] * C[i][j];
        
        cout << fixed << setprecision(2) << cost/a+1e-6 << endl;
    }
}
