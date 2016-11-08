//10250
//The Other Two Trees
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

struct Point {
    double x, y;
    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    double dist(Point& other) {
        return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
    }
};



int main() {
    Point A, B;
    while(cin >> A.x >> A.y >> B.x >> B.y) {
        Point M((A.x+B.x)/2, (A.y+B.y)/2);
        double dx = (A.x-B.x)/2;
        double dy = (A.y-B.y)/2;
        
        Point C(M.x-dy, M.y+dx);
        Point D(M.x+dy, M.y-dx);
        
        cout << fixed << setprecision(10) << D.x << " " << D.y << " " << C.x << " " << C.y << endl;
    }    
}

