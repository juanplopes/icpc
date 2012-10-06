//361
//Cops and Robbers
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

    int product(Point a, Point b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    bool left(Point a, Point b) {
        return product(a, b) < 0;
    }

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
    }
    
    bool insideSegment(Point a, Point b) {
        return product(a, b) == 0 && min(a,b) < *this && *this < max(a,b);    
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

bool checkInside(Point* P, int n, Point v) {
    for(int i=0; i<n; i++) {
        int j = (i+1)%n;
        if (v == P[i] || v.insideSegment(P[i], P[j])) 
            return true;
    }

    for(int i=0; i<n; i++) {
        int j = (i+1)%n;
        if (!v.left(P[i], P[j]))
            return false;
    }

    return true;
}


Point C[250], R[250], CS[250], RS[250];

int main() {
    int c, r, o, tt=1;
    while(cin >> c >> r >> o, c|r|o) {
        for(int i=0; i<c; i++)
            cin >> C[i].x >> C[i].y;        

        for(int i=0; i<r; i++)
            cin >> R[i].x >> R[i].y;        
            
        int cs = convexHull(C, c, CS);
        int rs = convexHull(R, r, RS);
        
        /*for(int i=0; i<cs; i++) {
            cout << " " << CS[i].x << " " << CS[i].y << endl;   
        }*/
        
        cout << "Data set " << tt++ << ":" << endl;
        for(int i=0; i<o; i++) {
            Point p; cin >> p.x >> p.y;
            cout << "     Citizen at (" << p.x << "," << p.y << ") is ";
            if (checkInside(CS, cs, p) && cs > 2)     
                cout << "safe." << endl;
            else if (checkInside(RS, rs, p) && rs > 2)
                cout << "robbed." << endl;
            else
                cout << "neither." << endl;
        }
        cout << endl;
        
    }   
}
