//1205
//Color a Tree
//Graphs;Job Scheduling
#include <iostream>
#include <vector>
#include <set>
#define MAX 1008
using namespace std;

struct Cost {
    int a, b, t, v;
    Cost() { }
    Cost(int a, int b, int t, int v) : a(a), b(b), t(t), v(v) {}

    inline bool operator <(const Cost &c) const {
        int cra = a*c.t, crb = c.a*t;
        if (cra!=crb) return cra>crb;
        return v<c.v;
    }
};

int P[MAX], M[MAX];
set<Cost> S;
Cost C[MAX];

int findParent(int v) {
    if (M[v] == v) return v;
    return M[v] = findParent(M[v]);
}

int main() {
    int n, r;
    while(cin >> n >> r, n|r) {
        for(int i=1; i<=n; i++) {
            int a; cin >> a;
          
            P[i] = 0;
            M[i] = i;
            C[i] = *S.insert(Cost(a, a, 1, i)).first;
        }
        
        for(int i=1; i<=n-1; i++) {
            int u, v; cin >> u >> v;
            P[v] = u;
        }
       
        int total = 0, time = 0;
        while(!S.empty()) {
            Cost c = *S.begin();
            int pid = findParent(P[c.v]);
            if (pid == 0) {
                total += time * c.a + c.b;
                time += c.t;
                S.erase(c);
                M[c.v] = 0;
            } else {
                Cost d = *S.find(C[pid]);
                Cost e(c.a + d.a, c.b + d.b + c.a * d.t, c.t + d.t, d.v);
                
                S.erase(c);
                S.erase(d);
                S.insert(e);

                M[c.v] = d.v;
                C[e.v] = e;
            }
        }
        cout << total << endl;

    }
}
