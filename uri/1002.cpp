//1002
//Area of a Circle
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159;
    int r;
    while(cin >> r)
        cout << "A=" << fixed << setprecision(4) << pi*r*r << endl;
}
