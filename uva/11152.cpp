//11152
//Colourful Flowers
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define PI acos(-1)
using namespace std;

int main() {
    double a, b, c;
    while(cin >> a >> b >> c) {
        double s = (a+b+c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        double r1 = sqrt((s-a)*(s-b)*(s-c)/s), r2 = a/4*b*c/area;
        
        double area1 = PI*r1*r1;
        double area2 = area-area1;
        double area3 = PI*r2*r2-area;
        
        cout << fixed << setprecision(4) << area3 << " " << area2 << " " << area1 << endl;
    }    
}

