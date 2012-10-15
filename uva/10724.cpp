//10724
//Road Construction
//Graphs;Shortest Path;Floyd-Warshall
#include <iostream>
#include <cmath>
#define MAX 58
#define EP 1e-6
#define eq(x, y) abs(x-y) < EP
using namespace std;

double G[MAX][MAX], X[MAX], Y[MAX];

double dist(int i, int j) {
    return sqrt(pow(X[i]-X[j], 2.0) + pow(Y[i]-Y[j], 2.0));
}

struct Answer {
    double x, d;
    int i, j;
    Answer(double x, double d, int i, int j) : x(x), d(d), i(i), j(j) {}
    
    bool operator <(const Answer& o) const{
        if (!eq(x, o.x)) return x < o.x;
        if (!eq(d, o.d)) return d > o.d;
        if (i!=o.i) return i>o.i;
        if (j!=o.j) return j>o.j;
        return false;
    }
    
    bool valid() {
        return x-1 > EP;
    }
};

int main() {
    int n, m;
    while(cin >> n >> m, n|m) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++)
                G[i][j] = 1e8;
                
            G[i][i] = 0;
            cin >> X[i] >> Y[i];
        }

        for(int i=0; i<m; i++) {
            int x, y; 
            cin >> x >> y;
            G[x][y] = G[y][x] = dist(x, y);
        }
        
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
     
        Answer maxx(0, 0, 0, 0);
            
        for(int u=1; u<=n; u++) {
            for(int v=1; v<=n; v++) {
                double improve = 0, uv = dist(u, v);
                
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                        improve += G[i][j] - min(G[i][j], 
                            min(G[i][u]+uv+G[v][j], G[i][v]+uv+G[u][j]));

                maxx = max(maxx, Answer(improve, uv, u, v));
            }
        }
        
        if (maxx.valid()) {
            cout << maxx.i << " " << maxx.j << endl;
        } else {
            cout << "No road required" << endl;
        }
    }    
}
