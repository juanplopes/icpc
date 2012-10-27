//10594
//Data Flow
//Graphs;Maximum Flow;Min Cost;Cycle Canceling
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 110
using namespace std;

struct Item {
    long long v, p, c;
    Item() {}
    Item(long long v, long long p, long long c) : v(v), p(p), c(c) {}
};

long long C[MAX][MAX], M[MAX];
long long F[MAX][MAX], G[MAX][MAX], P[MAX], n, a, b, qn;
bool V[MAX];
Item Q[MAX];


long long send(long long s, long long t) {
    memset(V, 0, sizeof(V));
    qn = 0;

    Q[qn++] = Item(s, -1, 1L<<60);
    V[s] = true;

    for(long long i=0; i<qn; i++) {
        Item item = Q[i];

        if (item.v == t) {
            long long sent = item.c;
            while(item.p != -1) {
                Item parent = Q[item.p];
                F[parent.v][item.v] += sent;
                F[item.v][parent.v] -= sent;
                item = parent;
            }
            
            return sent;
        }
        
        for(long long j=0; j<n; j++) {
            long long residual = G[item.v][j]-F[item.v][j];
            if (!V[j] && residual) {
                V[j] = true;
                Q[qn++] = Item(j, i, min(item.c, residual));
            }
        }
    }
    
    return 0;
}

bool cancel_cycle(long long source) {
    memset(M, 0x1f, sizeof M);
    M[source] = 0;

    bool cycle = false;
    long long v;

    for(long long k=0; k<n; k++)
    for(long long i=0; i<n; i++)
    for(long long j=0; j<n; j++) {
        if (G[i][j] - F[i][j] && M[i]+C[i][j]<M[j]) {
            cycle = k+1==n;
            v = i;
            
            M[j] = M[i] + C[i][j];
            P[j] = i;
        }
        
        if (F[i][j]>0 && M[j]-C[i][j]<M[i]) {
            cycle = k+1==n;
            v = j;
            
            M[i] = M[j] - C[i][j];
            P[i] = j;
        }
    }

    if (not cycle) return false;
    
    for(long long k=0; k<n; k++)
        v = P[v];
    
    long long i=v, minn=1L<<60;
    
    do {
        if (F[P[i]][i] < 0) {
            minn = min(minn, -F[P[i]][i]);
        } else {
            minn = min(minn, G[P[i]][i] - F[P[i]][i]);
        }
    } while (i = P[i], i!=v);

    do {
        F[P[i]][i] += minn;
        F[i][P[i]] -= minn;
    } while (i = P[i], i!=v);

    return true;
}

int main() {
    long long m;
    while(cin >> n >> m) {
        n++;
        memset(G, 0, sizeof(G));
        memset(F, 0, sizeof(F));
        memset(C, 0, sizeof(C));

        for(long long i=0; i<m; i++) {
            long long x, y, c;
            cin >> x >> y >> c;
            
            C[x][y] = C[y][x] = c;
            G[x][y] = G[y][x] = 1;
        }
        long long d, k; cin >> d >> k;
        G[0][1] = d;
        G[1][0] = d;
        
        for(long long i=1; i<n; i++) {
            for(long long j=1; j<n; j++) {
                G[i][j] *= k;
            }        
        }
        
        long long total = 0;
        while(long long sent = send(0, n-1))
            total += sent;

        while(cancel_cycle(0));

        long long cost = 0;
        for(long long i=0; i<n; i++)
            for(long long j=0; j<n; j++)
                if (F[i][j] > 0) {
  //                  cout << " " << i << " " << j << " " << F[i][j] << " " << C[i][j] << endl;
                    cost += F[i][j] * C[i][j];
                } else if (F[i][j] < 0) {
//                    cout << " " << i << " " << j << " " << F[i][j] << " " << C[i][j] << endl;
               
                }
        
        if (total != d)
            cout << "Impossible." << endl;
        else
            cout << cost << endl;
    }
}
