//1111
//Squares
//Math;Geometry;Square Distance
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    double dist(const Point A) const {
        return sqrt(pow(A.x-x,2)+pow(A.y-y,2));
    }
    
    double toLine(const Point A, const Point B) const {
        double scale = ((x - A.x) * (B.x - A.x) + (y-A.y)*(B.y-A.y)) / 
                       ((B.x - A.x) * (B.x - A.x) + (B.y-A.y)*(B.y-A.y));
                       
        return dist(Point(A.x + scale*(B.x-A.x), A.y + scale * (B.y-A.y)));
    }
    
    double toSegment(const Point A, const Point B) const {
        if ((x - A.x) * (B.x - A.x) + (y-A.y)*(B.y-A.y) <= 1e-6)
            return dist(A);

        if ((x - B.x) * (A.x - B.x) + (y-B.y)*(A.y-B.y) <= 1e-6)
            return dist(B);

        return toLine(A, B);
    }
    
    int signal(const Point& a, const Point& b) const  {
        double sig = (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
        if (abs(sig) < 1e-6) return 0;
        if (sig < 0) return -1;
        return 1;
    }
    
    Point rotateWith(const Point origin, double si, double co, double scale) const {
        double tx = this->x - origin.x;
        double ty = this->y - origin.y;
        double x = (tx * co + ty * si)/scale;
        double y = (tx * -si + ty * co)/scale;
        return Point(origin.x + x, origin.y + y);
        
    }
};

struct Square {
    int id;
    Point a, b, c, d;
    Square(int id, Point x, Point y) : id(id), 
        a(x.x, x.y), b(x.rotateWith(y, 0.707106781, 0.707106781, 1.41421356)), 
        c(y.x, y.y), d(x.rotateWith(y, -0.707106781, 0.707106781, 1.41421356)) {}
    
    bool inside(const Point p) const {
        int sig = a.signal(p, b);
        if (sig == 0) return false;
        if (sig != b.signal(p, c)) return false;
        if (sig != c.signal(p, d)) return false;
        if (sig != d.signal(p, a)) return false;
        return true;
    }
    
    double dist(const Point p) const {
        if (inside(p)) return 0.0;
        return min(min(p.toSegment(a,b), p.toSegment(b, c)), min(p.toSegment(c,d), p.toSegment(d,a)));
    }
};

struct DistToP {
    Point p;
    DistToP(Point p) : p(p) {}
    
    inline bool operator() (const  Square &a, const  Square &b)  {
        double da = a.dist(this->p), db=b.dist(this->p);
        if (abs(da-db) > 1e-6) return da<db;
        return a.id < b.id;
    }
};

vector<Square> V;

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        Point x,y; cin >> x.x >> x.y >> y.x >> y.y;
        V.push_back(Square(i, x, y));        
    }    

    Point p;
    cin >> p.x >> p.y;

    sort(V.begin(), V.end(), DistToP(p));
    for(int i=0;i<n; i++) {
        if (i) cout << " ";
        cout << V[i].id;  
    }
    cout << endl;
}
