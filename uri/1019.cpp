//1019
//Time Conversion
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int x;
    while(cin >> x) {
        cout << x/60/60 << ":" << x/60%60 << ":" << x%60 << endl;
    }
}
