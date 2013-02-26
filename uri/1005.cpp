//1005
//Average 1
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    while(cin >> a >> b)
        cout << "MEDIA = " << fixed << setprecision(5) << (3.5*a+7.5*b)/11 << endl;
}
