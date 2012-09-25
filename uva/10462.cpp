//10462
//Is There A Second Way Left?
//Graphs;Minimum Spanning Tree;Kruskal
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Edge {
    int x, y, v;
    inline bool operator <(const Edge& that) const {
        return this->v < that.v;
    }    
};

Edge E[205];
int P[105], S[105];

inline int findset(int v) {
    if (P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return -1;
    if (a>b) swap(a,b);
    P[b] = a;
    return a;
}

int best(int n, int m, int skip) {
    for(int i=0; i<=n; i++)
        P[i] = i;

    int total=0, count=0;
    for(int i=0; i<m && count < n-1; i++) {
        if(i!=skip && unionset(E[i].x, E[i].y) != -1) {
            total += E[i].v;
            if (skip == -1) 
                S[count] = i;
            count++;
        }
    }
    if (count == n-1)
        return total;
    else
        return -1;
}

int main() {
    int t; cin >> t;
    for(int tt=1; tt<=t; tt++) {
        int n, m; cin >> n >> m;
        
        for(int i=0; i<m; i++)
            cin >> E[i].x >> E[i].y >> E[i].v;

        sort(E, E+m);
        
        cout << "Case #" << tt << " : ";
        
        if (best(n, m, -1) == -1) {
            cout << "No way" << endl;        
            continue;
        }
        
        int minn = 1<<30;
        for(int i=0;i<n-1; i++) {
            int value = best(n, m, S[i]);
            if (value != -1)
                minn = min(minn, value);
        }
        
       
        if (minn < 1<<30)
            cout << minn << endl;
        else
            cout << "No second way" << endl;
    }
}
