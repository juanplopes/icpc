//10065
//Useless Tile Packers
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
    double area = 0.0;        
    for(int i=0; i<a; i++) {
        int j = (i+1)%a;
        area += (A[i].x + A[j].x) * (A[i].y - A[j].y);
    }
    area /= 2.0;
    return area;
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

Point P[110], S[110];

int main() {
    int n, tt=0;
    while(cin >> n, n) {
        for(int i=0; i<n; i++) {
            int x, y; cin >> x >> y;
            P[i] = Point(x, y);
        }

        int m = convexHull(P, n, S);        
        double original = abs(area(P, n));        
        double modified = abs(area(S, m));
        double ratio = modified > 0 ? 100*(1.0-(original/modified)) : 0;
        
        cout << "Tile #" << ++tt << endl;
        cout << "Wasted Space = " << fixed << setprecision(2) << ratio << " %" << endl;
        cout << endl;
    }    
    

}
