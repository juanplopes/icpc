//10316
//Airline Hub
//Math;Geometry;Great-Circle Distance
#define PI 3.14159265
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
    double dx, dy;

    Point() {}
    Point(double x, double y) : x(x), y(y) { 
        dx = x/180.0*PI;
        dy = y/180.0*PI;
    }

    double distance(Point& p) {
        return acos(cos(p.dx) * cos(this->dx) * cos(this->dy - p.dy) + sin(p.dx) * sin(this->dx));
    }
};

Point P[1050];

int main() {
    int n;
    while(cin >> n) {
        for(int i=0; i<n; i++) {
            double x,y; cin >> x >> y;
            P[i] = Point(x,y);
        }

        double minn = 1000000000;
        int mini = 0;
        for(int i=0; i<n; i++) {
            double maxx = 0;
            for(int j=0;j<n;j++)
                maxx = max(maxx, P[i].distance(P[j]));
            
            if (maxx < minn || abs(maxx - minn) < 1e-6) {
                mini = i;
                minn = maxx;
            }
        }
        
        cout << fixed << setprecision(2) << P[mini].x << " " << P[mini].y << endl;
    }    
    

}
