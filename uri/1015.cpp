//1015
//Distance Between two points
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2) {
        cout << fixed << setprecision(4) << sqrt(pow(x2-x1, 2) + pow(y2-y1,2)) << endl;
    }
}
