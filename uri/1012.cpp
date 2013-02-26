//1012
//Area
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159;
    double a, b, c;
    while(cin >> a >> b >> c) {
        cout << "TRIANGULO: " << fixed << setprecision(3) << a*c/2 << endl;
        cout << "CIRCULO: " << fixed << setprecision(3) << pi*c*c << endl;
        cout << "TRAPEZIO: " << fixed << setprecision(3) << c*(a+b)/2 << endl;
        cout << "QUADRADO: " << fixed << setprecision(3) << b*b << endl;
        cout << "RETANGULO: " << fixed << setprecision(3) << a*b << endl;
    }
        
}
