//10694
//f91
//Misc;Ad hoc
#include <iostream>
using namespace std;

int f91(int x) {
    if (x<=100)
        return f91(f91(x+11));
    else
        return x-10;
}

int main() {
    int n;
    while(cin >> n, n)
        cout << "f91(" << n << ") = " << f91(n) << endl;
}
