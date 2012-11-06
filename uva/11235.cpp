//11235
//Frequent Values
//Misc;Segment Tree;Range Maximum Query
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 600100
#define ull long long
using namespace std;

struct Segtree {
    int T[MAX], V[MAX];
    int n;

    Segtree() {
        clear(1);
    }
    
    void clear(int n) {
        this->n = n;   
        memset(V, 0, (n+1)*sizeof(int));            
        build(1, 1, n);
    }
    
    void build(int v, int a, int b) {
        T[v] = a;
        
        if (a>=b) return;
        build(2*v, a, (a+b)/2);
        build(2*v+1, (a+b)/2+1, b);
    }
    
    int maxv(int a, int b) {
        return V[a]<V[b] ? b : a;
    }
    
    int query(int v, int a, int b, int i, int j) {
        if (i>b || j<a || j<i)
            return 0;

        if (i<=a && b<=j) 
            return T[v];
        
        return maxv(
            query(v*2, a, (a+b)/2, i, j),
            query(v*2+1, (a+b)/2+1, b, i, j));
            
    }

    int update(int v, int a, int b, int i, int x) {
        if (a==b)
            return V[a] = x, T[v] = a;
        else if (i<=(a+b)/2)
            return T[v] = maxv(T[v*2+1], update(v*2, a, (a+b)/2, i, x));
        else
            return T[v] = maxv(T[v*2], update(v*2+1, (a+b)/2+1, b, i, x));
    }
    
    int query(int i, int j) {
        return query(1, 1, n, i, j);
    }
    
    int update(int i, int x) {
        return update(1, 1, n, i, x);
    }
};

Segtree T;
int S[MAX], E[MAX], C[MAX], N[MAX];

int main() {
    int n, q;
    while(cin >> n >> q, n) {
        T.clear(n);

        for(int i=1; i<=n; i++)
            cin >> N[i];

        for(int i=n; i>0; i--) {
            if (i<n && N[i] == N[i+1])
                E[i] = E[i+1];
            else
                E[i] = i;
        }

        for(int i=1; i<=n; i++) {
            if (i>1 && N[i] == N[i-1])
                S[i] = S[i-1];
            else
                S[i] = i;
            C[i] = E[i] - S[i] + 1;
            T.update(i, C[i]);
        }

        for(int i=0; i<q; i++) {
            int a, b; cin >> a >> b;
            if (N[a] == N[b])
                cout << b-a+1 << endl;
            else {
                int case1 = E[a] - max(S[a], a) + 1;
                int case2 = min(E[b], b) - S[b] + 1;
                int case3 = C[T.query(E[a] + 1, S[b]-1)];
                cout << max(case1, max(case2, case3)) << endl;
            }
        }
    }
}
