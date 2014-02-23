//1051
//Taxes
//Misc;Beginner
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

int main() {
    double v;
    while(cin >> v) {
        double x = 0;
        if (v>0) {
            x += min(v, 2000.0) * 0;
            v -= 2000;
        }

        if (v>0) {
            x += min(v, 1000.0) * 0.08;
            v -= 1000;
        }

        if (v>0) {
            x += min(v, 1500.0) * 0.18;
            v -= 1500;
        }

        if (v>0)
            x += v*0.28;

        cout << fixed << setprecision(2) << "R$ " << x << endl;

    }
}
