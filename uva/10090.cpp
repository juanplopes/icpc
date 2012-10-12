//10090
//Marbles
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

ull solve(ull a, ull b, ull c) {
    ull x, y;
    ull g = euclid(a, b, x, y);
    if (c%g) return -1;
    ull ag=a/g, bg=b/g, cg=c/g;
    return (x*cg%bg+bg)%bg;
}

int main() {
    ull n, c1, n1, c2, n2;
    
    while(cin >> n, n) {
        cin >> c1 >> n1 >> c2 >> n2;
        
        ull sol1=solve(n1, n2, n), sol2=solve(n2, n1, n);

        ull sol12=(n-n1*sol1)/n2, sol21=(n-n2*sol2)/n1;

        if (sol1 < 0 || sol12 < 0) {
            cout << "failed" << endl;
            continue;
        }

        ull cos1=c1*sol1+sol12*c2;
        ull cos2=c2*sol2+sol21*c1;
        if (cos1 < cos2)
            cout << sol1 << " " << sol12 << endl;
        else
            cout << sol21 << " " << sol2 << endl;
    }
}
