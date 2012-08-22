//109
//SCUD Busters
//Math;Geometry;Convex Hull
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool left(Point& a, Point& b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x) < 0;
    }

    static bool lesserX(Point& p1, Point& p2) {
        return p1.x < p2.x;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x && this->y == p.y;
    }

};

double area(Point* A, int a) {
    double area = 0;        
    for(int i=0; i<a; i++) {
        int j = (i+1)%a;
        area += (A[i].x + A[j].x) * (A[i].y - A[j].y);
    }
    return area / 2;
}

int convexHull(Point* P, int n, Point* S) {
    int m=0;
    S[m++] = *min_element(P, P+n, Point::lesserX);
    while(true) {
        Point cand = S[m-1];
        for(int j=0; j<n; j++)
            if (cand==S[m-1] or P[j].left(S[m-1], cand))
                cand = P[j];

        if (cand == S[0]) break;
        S[m++] = cand;
    }   
    return m;
}

//assumes convex polygon, ordered clockwise
//convex hull output is just that
bool checkInside(Point* P, int n, Point v) {
    for(int i=1; i<=n; i++)
        if (v.left(P[i-1], P[i%n]))
            return false;

    return true;
}


Point P[30][250], S[30][250];
int N[30], M[30];
bool V[30];

int main() {
    int n, k=0;
    while(cin >> n, n!=-1) {
        N[k] = n;
        for(int i=0; i<n; i++) {
            int x,y; cin >> x >> y;
            P[k][i] = Point(x,y);
        }
    
        M[k] = convexHull(P[k], n, S[k]);
    
        k++;
    }    
    
    int x, y;
    while(cin >> x >> y) {
        for(int i=0; i<k; i++)
            if (checkInside(S[i], M[i], Point(x,y)))
                V[i] = true;
    }

    double total = 0;
    for(int i=0; i<k; i++)
        if (V[i])
            total += area(S[i], M[i]);
    
    cout << fixed << setprecision(2) << total << endl;
}
