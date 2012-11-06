//11297
//Census
//Misc;Segment Tree;2D
#include <iostream>
#include <cstring>
#include <functional>
#define MAX 506
#define ull long long
using namespace std;

int P[MAX][MAX];

struct Point {
    int x, y, mx;
    Point() : x(0), y(0), mx(-1) {}
    Point(int x, int y, int mx) : x(x), y(y), mx(mx) { }
    
    bool operator <(const Point& other) const {
        return mx < other.mx;
    }
};

struct Segtree2d {
    Point T[2*MAX*MAX];
    int n, m;

    void clear(int n, int m) {
        this->n = n;   
        this->m = m;
        build(1, 1, 1, n, m);
    }
    
    int c(int s1, int s2) {
        return (s1+s2)/2;
    }
    
    Point build(int v, int a1, int b1, int a2, int b2) {
        if (a1>a2 || b1>b2) return def();

        if (a1 == a2 && b1 == b2)
            return T[v] = Point(a1, b1, P[a1][b1]);
        
        T[v] = def();
        T[v] = maxv(T[v], build(4*v-2, a1,          b1,          c(a1, a2), c(b1, b2)));
        T[v] = maxv(T[v], build(4*v-1, c(a1, a2)+1, b1,          a2,        c(b1, b2)));
        T[v] = maxv(T[v], build(4*v+0, a1,          c(b1, b2)+1, c(a1, a2), b2       ));
        T[v] = maxv(T[v], build(4*v+1, c(a1, a2)+1, c(b1, b2)+1, a2,        b2       ));
        return T[v];
    }
    
    //virtual apenas para permitir árvore de mínimo
    virtual Point maxv(Point a, Point b) {
        return max(a, b);
    }
    
    virtual Point def() {
        return Point(0, 0, -1);
    }
    
    
    Point query(int v, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
        if (x1>a2 || y1>b2 || x2<a1 || y2<b1 || a1>a2 || b1>b2)
            return def();

        if (x1<=a1 && y1<=b1 && a2<=x2 && b2<=y2) 
            return T[v];
        
        Point mx = def();
        
        mx = maxv(mx, query(4*v-2, a1,          b1,          c(a1, a2), c(b1, b2), x1, y1, x2, y2));
        mx = maxv(mx, query(4*v-1, c(a1, a2)+1, b1,          a2,        c(b1, b2), x1, y1, x2, y2));
        mx = maxv(mx, query(4*v+0, a1,          c(b1, b2)+1, c(a1, a2), b2,        x1, y1, x2, y2));
        mx = maxv(mx, query(4*v+1, c(a1, a2)+1, c(b1, b2)+1, a2,        b2,        x1, y1, x2, y2));
        
        return mx;
    }

    Point query(int x1, int y1, int x2, int y2) {
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }

    Point update(int v, int a1, int b1, int a2, int b2, int x, int y, int value) {
        if (a1>a2 || b1>b2) return def();

        if (x>a2 || y>b2 || x<a1 || y<b1)
            return T[v];

        if (x==a1 && y==b1 && x==a2 && y==b2) 
            return T[v] = Point(x, y, value);
        
        Point mx = def();
        
        mx = maxv(mx, update(4*v-2, a1,          b1,          c(a1, a2), c(b1, b2), x, y, value));
        mx = maxv(mx, update(4*v-1, c(a1, a2)+1, b1,          a2,        c(b1, b2), x, y, value));
        mx = maxv(mx, update(4*v+0, a1,          c(b1, b2)+1, c(a1, a2), b2,        x, y, value));
        mx = maxv(mx, update(4*v+1, c(a1, a2)+1, c(b1, b2)+1, a2,        b2,        x, y, value));
        
        return T[v] = mx;
    }
    
    Point update(int x, int y, int value) {
        return update(1, 1, 1, n, m, x, y, value);
    }
};

struct Segtree2dMin : Segtree2d {
    Point maxv(Point a, Point b) {
        return min(a, b);
    }
    
    Point def() {
        return Point(0, 0, 1<<29);
    }
};

Segtree2d Tmax;
Segtree2dMin Tmin;

int main() {
    int n, m;
    while(cin >> n >> m) {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> P[i][j];

        Tmax.clear(n, m);
        Tmin.clear(n, m);
       
       
        int q; cin >> q;
        while(q--) {
            char cmd; 
            cin >> cmd;

            if (cmd == 'q') {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << Tmax.query(x1, y1, x2, y2).mx << " " << Tmin.query(x1, y1, x2, y2).mx << endl;
            } else {
                int x, y, v;
                cin >> x >> y >> v;
                Tmax.update(x, y, v);
                Tmin.update(x, y, v);
            }
        }
       
    
    }
}
