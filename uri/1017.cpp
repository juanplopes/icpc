//1017
//Fuel Spent
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    while(cin >> a >> b) {
        cout << fixed << setprecision(3) << a*b/12 << endl;
    }
}
