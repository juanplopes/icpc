//1008
//Salary
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b; float c;
    while(cin >> a >> b >> c) {
        cout << "NUMBER = " << a << endl;
        cout << "SALARY = U$ " << fixed << setprecision(2) << b*c << endl;
    }
}
