//11626
//Convex Hull
//Math;Geometry;Point Sort
#include <iostream>
#include <algorithm>
#define long2 long long
using namespace std;

struct Point {
    long2 x, y;

    Point() {}
    Point(long2 x, long2 y) : x(x), y(y) {}

    long2 signal(Point& a, Point& b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    inline bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }
};

Point P[100050], L[100050], U[100050], C[100050];

void print(Point* P, int n) {
    for(int i=0; i<n; i++)
        cout << P[i].x << " " << P[i].y << endl;
}

void printInv(Point* P, int n) {
    for(int i=n-1; i>=0; i--)
        cout << P[i].x << " " << P[i].y << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int m = 0;
        for(int i=0; i<n; i++) {
            long2 x, y; char c; 
            cin >> x >> y >> c;
            if (c=='Y')
                P[m++] = Point(x,y);
        }
        sort(P, P+m);
        int up=0, lo=0, ce=0;
        for(int i=1; i<m-1; i++) {
            long2 signal = P[i].signal(P[0], P[m-1]);
            if (signal < 0)
                U[up++] = P[i];
            else if (signal > 0)
                L[lo++] = P[i];
            else
                C[ce++] = P[i];
        }        
        
        
        cout << m << endl;
        cout << P[0].x << " " << P[0].y << endl;
            
        if (lo > 0)
            print(L, lo);
        else
            print(C, ce);

        cout << P[m-1].x << " " << P[m-1].y << endl;

        if (up > 0)
            printInv(U, up);
        else
            printInv(C, ce);
    }    
    
}
