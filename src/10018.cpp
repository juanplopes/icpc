//10018
//Reverse and Add
//Misc;Ad hoc
#include <iostream>
using namespace std;

long reverse(long a) {
    long b = 0;
    while(a) {
        b = b*10 + a%10;
        a /= 10;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        long a; cin >> a;
        for(int i=1; i<=1000; i++ ) {
            a = a + reverse(a);
            if (a == reverse(a)) {
                cout << i << " " << a << endl;
                break;            
            }
        }
    }
}
