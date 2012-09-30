//1185
//Wall
//Math;Geometry;Convex Hull;Monotone Chain
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define PI 3.14159265
using namespace std;

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool left(Point& a, Point& b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x) < 0;
    }

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
    }

    double dist(Point A) {
        return sqrt(pow(A.x-x,2.0)+pow(A.y-y,2.0));
    }
};

int convexHull(Point* P, int n, Point* S) {
    sort(P, P+n);

    int m=0;
    for(int i=0; i<n; i++) {
        while(m >= 2 && S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    for(int i=n-1, k=m; i >= 0; i--) {
        while(m >= k+2 && S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    return m;
}

Point P[1010], S[1010];

int main() {
    int n, r;
    while(cin >> n >> r) {
        for(int i=0; i<n; i++)
            cin >> P[i].x >> P[i].y;
        
        int s = convexHull(P, n, S);
        
        double total = 0;
        for(int i=0; i<s; i++)
            total += S[i].dist(S[(i+1)%n]);
        
        cout << floor(total + 2*PI*r + 0.5) << endl;
    }
}
