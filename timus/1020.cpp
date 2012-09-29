//1020
//Rope
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265
using namespace std;

struct Point {
    double x, y;

    Point() {}

    double dist(Point A) {
        return sqrt(pow(A.x-x,2)+pow(A.y-y,2));
    }
};

int main() {
    int n;
    double r;
    Point a, b, c;
    while(cin >> n >> r) {
        double total = 0;

        cin >> a.x >> a.y;
        b = a;
        for(int i=1; i<n; i++) {
            cin >> c.x >> c.y;
            total += b.dist(c);
            swap(b, c);
        }
        total += a.dist(b);
        
        cout << fixed << setprecision(2) << total + 2*PI*r << endl;
    }
}
