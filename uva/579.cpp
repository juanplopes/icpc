//579
//ClockHands
//Misc;Ad hoc
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int x, y; char c;
    while(cin >> x >> c >> y, x|y) {
        double a = x*30+(y/2.0);
        double b = y*6.0;
        double r = abs(a-b);
        if (r > 180.0)
            r = 360.0-r;
        
        cout << fixed << setprecision(3) << r << endl;
        
    }
    
}
