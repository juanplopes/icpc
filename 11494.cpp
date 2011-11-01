//11494
//Queen
//Misc;Ad hoc
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
    int x, y, a, b;
    while(cin >> x >> y >> a >> b, x|y|a|b) {
        if (x==a && y==b)
            cout << 0 << endl;
        else if (x==a || y==b || x+y == a+b || x-y==a-b)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
