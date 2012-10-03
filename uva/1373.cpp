//1373
//Pictura ex Machina
//Math;Geometry;Segment Rotation
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double PI = 2*acos(0.0);

struct Point {
    double x, y;
    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    Point rotateWith(const Point origin, double si, double co, double scale) const {
        double tx = this->x - origin.x;
        double ty = this->y - origin.y;
        double x = (tx * co + ty * si)/scale;
        double y = (tx * -si + ty * co)/scale;
        return Point(origin.x + x, origin.y + y);
        
    }
};

double round4(double a) {
    if (a<0) return 0.0;
    return floor(a*10000+0.5)/10000.0;   
}

int main() {
    Point a, b;
    double minx=1<<30, maxx=0, miny=1<<30, maxy=0;
    while(cin >> a.x >> a.y >> b.x >> b.y) {
        Point c = b.rotateWith(a, sin(-PI/4), cos(-PI/4), sqrt(2.0));
        
        minx = min(minx, min(min(a.x, b.x), c.x));
        miny = min(miny, min(min(a.y, b.y), c.y));
        maxx = max(maxx, max(max(a.x, b.x), c.x));
        maxy = max(maxy, max(max(a.y, b.y), c.y));
    }
        
    cout << fixed << setprecision(4) << round4(maxx - minx) << " " << round4(maxy - miny) << endl;
}
