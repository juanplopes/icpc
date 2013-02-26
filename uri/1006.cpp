//1006
//Average 2
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    while(cin >> a >> b >> c)
        cout << "MEDIA = " << fixed << setprecision(1) << (2*a+3*b+5*c)/10 << endl;
}
