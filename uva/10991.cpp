//10991
//Region
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define PI 3.141592654
using namespace std;

int main() {
    int tests; cin >> tests;
    
    double R1, R2, R3;
    while(cin >> R1 >> R2 >> R3) {
        double a = R1+R2, b = R2+R3, c = R3+R1;
        double C = acos((a*a + b*b - c*c) / (2*a*b));
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((c*c + a*a - b*b) / (2*c*a));
        
        double p = (a+b+c)/2;
        double area = sqrt(p*(p-a)*(p-b)*(p-c));
        
        double s1 = B/2 * R1*R1;
        double s2 = C/2 * R2*R2;
        double s3 = A/2 * R3*R3;
        
        cout << fixed << setprecision(6) << area-s1-s2-s3 << endl;
    }    
}

