//13045
//Drawing polygon
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
    int N;
    double L, X, Y;
   
    while(cin >> N >> L >> X >> Y) {
        if (test) cout << endl;
        double A = 0;
        double AI = PI - PI*(N-2)/N;
        
        cout << "Case #" << ++test << ":" << endl;
        
        cout << fixed << setprecision(6);
        for(int i=0; i<N; i++) {
            cout << X << " " << Y << endl;
            
            X += L*cos(A);
            Y += L*sin(A);
            A+=AI;
        }
    }    
}

