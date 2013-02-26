//1014
//Consumption
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x, y;
    while(cin >> x >> y) {
        cout << fixed << setprecision(3) << x/y << " km/l" << endl;
    }
}
