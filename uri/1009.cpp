//1009
//Salary with Bonus
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string s;
    float a, b;
    while(cin >> s >> a >> b) {
        cout << "TOTAL = R$ " << fixed << setprecision(2) << a+b*0.15 << endl;
    }
}
