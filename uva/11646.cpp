//11646
//Athletics Track
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define PI acos(-1)
#define EPS 1e-8
using namespace std;

double perimeter(double x, double f) {
    return 2*atan(1/f)*sqrt(x*x+f*f*x*x)+2*f*x;
}

int main() {
    int test = 0;
    double L, W; char temp;
    while(cin >> L >> temp >> W) {
        double F = L/W;
        double begin = 0, end = 1000;
        while(abs(begin-end)>EPS) {
            double mid = (begin+end)/2;
            if (perimeter(mid, F) > 400)
                end = mid;
            else
                begin = mid;
        }
        
        cout << "Case " << ++test << ": " << fixed << setprecision(10) << begin*F << " " << begin << endl;
    }    
}

