//1010
//Simple Calculate
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    float a, b, c, d;
    while(cin >> a >> a >> b >> c >> c >> d) {
        cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << a*b+c*d << endl;
    }
}
