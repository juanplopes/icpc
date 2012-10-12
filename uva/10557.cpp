//10557
//XYZZY
//Graphs;Shortest Path;Bellman Ford
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Edge {
    int a, b;
    Edge(int a, int b) : a(a), b(b) {}
};

int X[MAX], M[MAX], V[MAX], n;
vector<Edge> E;

bool reach(int v, int t) {
    if (v==t) return true;
    V[v] = true;
    for(int i=0; i<E.size(); i++) {
        Edge e = E[i];
        if (e.a == v && !V[e.b] && reach(e.b, t))
            return true;
    }
    return false;
}

int main() {
    while(cin >> n, n!=-1) {
        memset(V, 0, sizeof(V));
        E.clear();
        for(int a=1; a<=n; a++) {
            int k; cin >> X[a] >> k;
            
            for(int j=0; j<k; j++) {
                int b; cin >> b;
                E.push_back(Edge(a, b));
            }
        }
        
        M[1] = 100;
        for(int a=2; a<=n; a++)
            M[a] = -1<<29;

        for(int k=0; k<n-1; k++) {
            for(int i=0; i<E.size(); i++) {
                Edge e = E[i];
                if (M[e.a]<=0) continue;
                M[e.b] = max(M[e.b], M[e.a] + X[e.b]);
            }
        }
        
        bool cycle = false;
        for(int i=0; i<E.size(); i++) {
            Edge e = E[i];
            if (M[e.a]<=0) continue;
            cycle |= M[e.a]+X[e.b] > M[e.b] && reach(e.a, n);
        }
        
        
        if (M[n] > 0 || cycle) {
            cout << "winnable" << endl;
        } else {
            cout << "hopeless" << endl;
        }
            
    }
}
