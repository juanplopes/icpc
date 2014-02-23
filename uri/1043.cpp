//1043
//Triangle
//Misc;Beginner
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    while(cin >> a >> b >> c) {
        cout << fixed << setprecision(1);
        if (a+b>c && a+c>b && b+c>a) {
            cout << "Perimetro = " << (a+b+c) << endl;
        } else {
            cout << "Area = " << (b*c + 0.5*(a-b)*c) << endl;
        }
        
    }
}
