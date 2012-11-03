//11402
//Ahoy, Pirates!
//Misc;Segment Tree;Lazy Propagation
#include <iostream>
#include <string>
#include <cstring>
#define MAX 3000100
#define ull long long
using namespace std;

struct Node { 
    int a, b;
    int pending;

    Node() : a(0), b(0), pending(0) {}
    Node(int a) : a(a), b(0), pending(0) { }
    Node(int a, int b) : a(a), b(b), pending(0) { }

    Node change(int n) {
        if (n==1) {
            b += a;
            a = 0;
            pending = n;
        } else if (n==2) { 
            a += b;
            b = 0;
            pending = n;
        } else if (n==3) {
            swap(a, b);
            pending = 3-pending;
        }

        return *this;
    }
    
    Node operator +(Node x) {
        return Node(a+x.a, b+x.b);    
    }
};

struct Segtree {
    Node T[MAX];
    int n;

    void clear(int n, int *P) {
        this->n = n;               
        
        build(1, 1, n, P);
    }
    
    Node build(int v, int a, int b, int *P) {
        if (a==b)
            return T[v] = Node(1-P[a], P[a]);
        else
            return T[v] = 
                build(2*v, a, (a+b)/2, P) + 
                build(2*v+1, (a+b)/2+1, b, P);
    }
    
    Node update(int v, int a, int b, int i, int j, int carry, int increment) {
        T[v].change(carry);

        if (i>b || j<a)
            return Node(0);

        if (i<=a && b<=j) 
            return T[v].change(increment);
        
        Node answer = 
            update(v*2, a, (a+b)/2, i, j, T[v].pending, increment) + 
            update(v*2+1, (a+b)/2+1, b, i, j, T[v].pending, increment);
        
        T[v] = T[v*2] + T[v*2+1];
        
        return answer;
    }

    Node update(int i, int j, int inc) {
        return update(1, 1, n, i, j, 0, inc);
    }

    Node query(int i, int j) {
        return update(i, j, 0);
    }

};

Segtree T;
int P[MAX];
string s;

int main() {
    int cases; cin >> cases;
    
    for(int tt=1; tt<=cases; tt++) {
        cout << "Case " << tt << ":" << endl;

        int m; cin >> m;
        int n = 0;
        for(int i=0; i<m; i++) {
            int t;
            cin >> t >> s;
            for(int j=0; j<t; j++) {
                for(int k=0; k<s.size(); k++) {
                    P[++n] = s[k]-'0';
                }
            }
        }
        T.clear(n, P);
        
        int q; cin >> q;
        int query = 0;
        while(q--) {
            char cmd; int a, b;
            cin >> cmd >> a >> b;
            a++; b++;
            if (cmd == 'F') {
                T.update(a, b, 1);
            } else if (cmd == 'E') {
                T.update(a, b, 2);
            } else if (cmd == 'I') {
                T.update(a, b, 3);
            } else {
                Node node = T.query(a, b);
                cout << "Q" << ++query << ": " << node.b << endl;
            }
        }
    }
}
