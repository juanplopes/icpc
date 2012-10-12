//10104
//Euclid Problem
//Math;Extended Euclid
#include <iostream>
#define ull long long
using namespace std;

ull euclid(ull a, ull b, ull& rx, ull& ry) {
    if (!b) return rx=1, ry=0, a;
    
    ull q = a/b;
    ull x, y;
    ull g = euclid(b, a-q*b, x, y);
    return rx=y, ry=x-q*y, g;
}

int main() {
    ull a, b;
    
    while(cin >> a >> b) {
        ull x, y;
        ull d = euclid(a,b,x,y);

        cout << x << " " << y << " " << d << endl;
    }
}
