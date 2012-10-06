//10652
//Board Wrapping
//Math;Geometry;Convex Hull;Monotone Chain
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

double PI = 2*acos(0.0);

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    double product(Point a, Point b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    bool right(Point a, Point b) {
        return product(a, b) > 0;
    }

    double dist(Point b) {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));   
    }

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
    }
    
    Point rotateWith(const Point origin, double si, double co, double scale) const {
        double tx = this->x - origin.x;
        double ty = this->y - origin.y;
        double x = (tx * co + ty * si)/scale;
        double y = (tx * -si + ty * co)/scale;
        return Point(origin.x + x, origin.y + y);
        
    }
};

int convexHull(Point* P, int n, Point* S) {
    sort(P, P+n);

    int m=0;
    for(int i=0; i<n; i++) {
        while(m >= 2 && !S[m-1].right(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    for(int i=n-1, k=m; i >= 0; i--) {
        while(m >= k+2 && !S[m-1].right(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    return m;
}

double area(Point* A, int a) {
    double area = 0;        
    for(int i=0; i<a; i++) {
        int j = (i+1)%a;
        area += (A[i].x + A[j].x) * (A[i].y - A[j].y);
    }
    return area / 2;
}

Point P[3000], S[3000];

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;

        double initialArea = 0;
        for(int i=0; i<n; i++) {
            Point p; 
            cin >> p.x >> p.y;
            double w, h, angle; 
            cin >> w >> h >> angle;

            angle *= PI/180;

            Point a = Point(p.x-w/2, p.y-h/2).rotateWith(p, sin(angle), cos(angle), 1);
            Point b = Point(p.x-w/2, p.y+h/2).rotateWith(p, sin(angle), cos(angle), 1);
            Point c = Point(p.x+w/2, p.y+h/2).rotateWith(p, sin(angle), cos(angle), 1);
            Point d = Point(p.x+w/2, p.y-h/2).rotateWith(p, sin(angle), cos(angle), 1);
            
            P[i*4+0] = a;
            P[i*4+1] = b;
            P[i*4+2] = c;
            P[i*4+3] = d;

            initialArea += area(P+i*4, 4);
        }

        int s = convexHull(P, n*4, S);
        double finalArea = area(S, s);

        cout << fixed << setprecision(1) << abs(100*(initialArea/finalArea)) << " %" << endl;
    }   
}
