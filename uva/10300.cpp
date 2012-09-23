//10300
//Ecological Premium
//Misc;Ad hoc
#include <iostream>
using namespace std;

int main() {
    int n, f;
    cin >> n;
    while(n--) {
        cin >> f;
        double total = 0;
        for(int i=0; i<f; i++) {
            double a, b, c;
            cin >> a >> b >> c;
            total += a*c;
        }
        cout << (int)total << endl;
    }
}
