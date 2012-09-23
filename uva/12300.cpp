//12300
//Smallest Regular Polygon
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793238462
using namespace std;

double cot(double angle) {
    return cos(angle)/sin(angle);   
}
    
int main(){
    int x1, y1, x2, y2, n;
    while(cin >> x1 >> y1 >> x2 >> y2 >> n, x1 | y1 | x2 | y2 | n) {
        double d = sqrt(pow(x2-x1, 2.0)+pow(y2-y1, 2.0));
        int k = n/2;
        double s = sin(PI/n)/sin(PI*k/n)*d;
        double A = 0.25*n*s*s*cot(PI/n);
        setprecision(6);
        cout << fixed << A << endl;
    }
    
}
