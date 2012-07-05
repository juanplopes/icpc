//579
//ClockHands
//Misc;Ad hoc
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        if (x>y) {
            cout << ">" << endl;
        } else if (x<y) {
            cout << "<" << endl;
        } else {
            cout << "=" << endl;
        } 
    }
}
