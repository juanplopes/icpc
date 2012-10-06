//11096
//Nails
//Math;Geometry;Convex Hull;Monotone Chain
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define ull long long
using namespace std;

struct Point {
    ull x, y;

    ull product(Point a, Point b) {
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


Point P[120], S[120];

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int r, n;
        cin >> r >> n;
        for(int i=0; i<n; i++)
            cin >> P[i].x >> P[i].y;

        int s = convexHull(P, n, S);

        double final = 0.0;
        for(int i=0; i<s; i++)
            final += S[i].dist(S[(i+1)%n]);   

        final = max(final, (double)r);

        cout << fixed << setprecision(5) << final << endl;
    }   
}
