//11503
//Virtual Friends
//Misc;Union-Find
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int P[200001], C[200001];
map<string, int> M;

int parent(int v) {
    if (P[v] != v) {
        int p = P[v] = parent(P[v]);
        C[v] = C[p];
        return p;
    } else {
        return v;
    }
}

int person(string& s) {
    if (M.find(s) != M.end())
        return M[s];
    else {
        int r = M[s] = M.size();
        C[r] = 1; P[r] = r;
        return r;
    }
}

int main() {
    int t; cin >> t; t=0;
    int n;
    
    while(cin >> n) { 
        M.clear();
        while(n--) {
            string p, q; 
            cin >> p >> q;
            int a = person(p), b=person(q);
            int pa = parent(a), pb=parent(b);
            if (pa==pb) {
                cout << C[pa] << endl;
                continue;
            }
            if (pa < pb) swap(pa, pb);
            
            P[pb] = pa;
            cout << (C[pa]+=C[pb]) << endl;
        }
        
    }
}
