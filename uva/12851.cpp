//12851
//The Tinker's Puzzle
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define PI 3.141592654
using namespace std;

int main() {
    int test = 0, tests; cin >> tests;
    
    double D, V;
    while(cin >> D >> V) {
        cout << "Case " << ++test << ": ";
        cout << fixed << setprecision(3);
        
        cout << sqrt((3*282*V)/(D*PI*7))*4 << endl;
    }    
}

