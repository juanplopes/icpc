//HOMEM
//Homem, Elefante e Rato
//Misc;Segment Tree;Lazy Propagation
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 600100
#define ull long long
using namespace std;

struct Node { 
    int a, b, c; 
    int pending;

    Node() {}
    Node(int a) : a(a), b(0), c(0), pending(0) { }
    Node(int a, int b, int c) : a(a), b(b), c(c), pending(0) {}

    void change(int n) {
        pending += n;
        n = ((n%3)+3)%3;
        if (n==1) {
            swap(a, b); swap(a, c);
        } else if (n==2) { 
            swap(c, b); swap(c, a); 
        }
    }
    
    Node operator +(Node x) {
        return Node(a+x.a, b+x.b, c+x.c);    
    }
};

struct Segtree {
    Node T[MAX];
    int n;

    Segtree() {
        clear(1);
    }
    
    void clear(int n) {
        this->n = n;               
        
        while(n != n&-n)
            n += n&-n;
        
        build(1, 1, n);
    }
    
    void build(int v, int a, int b) {
        T[v] = Node(b-a+1);
        
        if (a<b) {
            build(2*v, a, (a+b)/2);
            build(2*v+1, (a+b)/2+1, b);
        }
    }
    
    Node update(int v, int a, int b, int i, int j, int inc1, int inc2) {
        T[v].change(inc2);

        if (i>b || j<a)
            return T[v];

        
        if (i<=a && b<=j) {
            T[v].change(inc1);
            return T[v];
        }
        
        return T[v] = 
            update(v*2, a, (a+b)/2, i, j, inc1, T[v].pending) + 
            update(v*2+1, (a+b)/2+1, b, i, j, inc1, T[v].pending);
        
    }

    Node update(int i, int j, int inc) {
        return update(1, 1, n, i, j, inc, 0);
    }
    
    Node query(int v, int a, int b, int i, int j, int inc) {
        T[v].change(inc);

        if (i>b || j<a)
            return Node(0);
        
        if (i<=a && b<=j)
            return T[v];
        
        Node answer = 
            query(v*2, a, (a+b)/2, i, j, T[v].pending) + 
            query(v*2+1, (a+b)/2+1, b, i, j, T[v].pending);

        T[v].pending = 0;

        return answer;
        
    }

    Node query(int i, int j) {
        return query(1, 1, n, i, j, 0);
    }

};

Segtree T;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        T.clear(n);
        for(int i=0; i<m; i++) {
            char cmd; int a, b;
            scanf(" %c %d %d", &cmd, &a, &b);
            if (cmd == 'M') {
                T.update(a, b, 1);
            } else {
                Node node = T.query(a, b);            
                printf("%d %d %d\n", node.a, node.b, node.c);
            } 
        }
        printf("\n");
    }
}
