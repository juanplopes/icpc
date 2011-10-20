#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#define MAX 200010

using namespace std;

struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
};   

vector<Road> G[MAX];
int n, m;
bool V[MAX];
int D[MAX], DO[MAX];

int updateD(int i) {
    D[i] = 0;
    for(int j=0; j<G[i].size(); j++) {
        if (G[i][j].c < D[G[i][j].v]) {
            D[G[i][j].v] = G[i][j].c;
            DO[G[i][j].v] = i;
        }
    }
}

int main() {
    while(cin >> n >> m, n|m) {
        int before = 0;
        memset(V, 0, sizeof(V));
        memset(D, 0x3F, sizeof(D));
        memset(G, 0, sizeof(G));
        
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Road(b, c));
            G[b].push_back(Road(a, c));
            before += c;
        }
        
        int total = 0;

        V[0] = true;
        updateD(0);
        
        for(int k=1; k<n; k++) {
            int minn=INT_MAX, minv;
            for(int i=0; i<n; i++) {
                if (!V[i] && D[i] < minn) {
                    minn = D[i];
                    minv = i;
                }
            }
            V[minv] = true;
            updateD(minv);
            total += minn;
        }
        
        cout << before-total << endl;
    }
    return 0;
}
