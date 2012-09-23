//10065
//Useless Tile Packers
//Math;Geometry;Convex Hull;Monotone Chain
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

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
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

Point P[110], S[110];

int main() {
    int n, tt=0;
    while(cin >> n, n) {
        for(int i=0; i<n; i++) {
            int x, y; cin >> x >> y;
            P[i] = Point(x, y);
        }

        double original = abs(area(P, n));        

        int m = convexHull(P, n, S);     
        double modified = abs(area(S, m));
        double ratio = 100*(1.0-(original/modified));
        
        cout << "Tile #" << ++tt << endl;
        cout << "Wasted Space = " << fixed << setprecision(2) << ratio << " %" << endl;
        cout << endl;
    }    
    

}
