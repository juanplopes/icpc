//273
//Jack Straws
//Graphs;DFS
#include <iostream>
#include <cstring>
#define MAX 100002
using namespace std;

static bool segment(int xi, int yi, int xj, int yj,
                        int xk, int yk) {
  return (xi <= xk || xj <= xk) && (xk <= xi || xk <= xj) &&
         (yi <= yk || yj <= yk) && (yk <= yi || yk <= yj);
}

static char direction(int xi, int yi, int xj, int yj,
                             int xk, int yk) {
  int a = (xk - xi) * (yj - yi);
  int b = (xj - xi) * (yk - yi);
  return a < b ? -1 : a > b ? 1 : 0;
}

bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  char d1 = direction(x3, y3, x4, y4, x1, y1);
  char d2 = direction(x3, y3, x4, y4, x2, y2);
  char d3 = direction(x1, y1, x2, y2, x3, y3);
  char d4 = direction(x1, y1, x2, y2, x4, y4);
  return (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
          ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) ||
         (d1 == 0 && segment(x3, y3, x4, y4, x1, y1)) ||
         (d2 == 0 && segment(x3, y3, x4, y4, x2, y2)) ||
         (d3 == 0 && segment(x1, y1, x2, y2, x3, y3)) ||
         (d4 == 0 && segment(x1, y1, x2, y2, x4, y4));
}

int G[20][20], V[20], A[20], B[20], C[20], D[20], n;

int dfs(int v, int comp) {
    V[v] = comp;
    for(int i=1; i<=n; i++)
        if (!V[i] && G[v][i])
            dfs(i, comp);
}

int main() {
    int t; cin >> t; t=0;
    while(cin >> n) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        for(int i=1; i<=n; i++) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
            for(int j=1;j<i; j++)
                G[i][j] = G[j][i] = intersect(A[i], B[i], C[i], D[i], A[j], B[j], C[j], D[j]);
        }
        
        int compn = 0;
        for(int i=1; i<=n; i++)
            if (!V[i])
                dfs(i, ++compn);
        
        if (t++) cout << endl;
        int a, b;
        while(cin >> a >> b, a|b) {
            cout << (V[a] == V[b]?"CONNECTED":"NOT CONNECTED") << endl;
        }
    }
    return 0;
}
