//1048
//Salary Increase
//Misc;Beginner
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double v;
    while(cin >> v) {
        double p;
        if (v<=400)
            p = 0.15;
        else if (v<=800)
            p = 0.12;
        else if (v<=1200)
            p = 0.10;
        else if (v<=1600)
            p = 0.07;
        else
            p = 0.04;

        cout << fixed << setprecision(2);
        
        cout << "Novo salario: " << v+(v*p) << endl;
        cout << "Reajuste ganho: " << (v*p) << endl;
        cout << setprecision(0) << "Em percentual: " << p*100 << " %" << endl;
    }
}
