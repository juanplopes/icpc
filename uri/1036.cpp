//1036
//Bhaskara's Fomula
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    while(cin >> a >> b >> c) {
        double delta = b*b-4*a*c;
        if (a == 0 || delta < 0) {
            cout << "Impossivel calcular" << endl;
            continue;
        }
        double r1 = (-b + sqrt(delta))/(2*a);
        double r2 = (-b - sqrt(delta))/(2*a);
        cout << "R1 = " << fixed << setprecision(5) << r1 << endl;
        cout << "R2 = " << fixed << setprecision(5) << r2 << endl;
    }
}
