//10104
//Euclid Problem
//Math;Extended Euclid
#include <iostream>
#define ull long long
using namespace std;

int euclid(int a, int b, int& rx, int& ry) {
    if (!b) return rx=1, ry=0, a;
    
    int q = a/b;
    int x, y;
    int g = euclid(b, a-q*b, x, y);
    return rx=y, ry=x-q*y, g;
}

int main() {
    int a, b;
    
    while(cin >> a >> b) {
        int x, y;
        int d = euclid(a,b,x,y);

        cout << x << " " << y << " " << d << endl;
    }
}
