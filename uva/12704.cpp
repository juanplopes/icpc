//12704
//Little Masters
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define PI acos(-1)
#define EPS 1e-8
using namespace std;

int main() {
    int test = 0, tests; cin >> tests;

    double X, Y, R;   
    while(cin >> X >> Y >> R) {
        double d = sqrt(X*X+Y*Y);
        cout << fixed << setprecision(2) << R-d << " " << R+d << endl;
    }    
}

