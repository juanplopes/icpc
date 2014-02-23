//1038
//Snack
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int x, y;
    while(cin >> x >> y) {
        double price = x==1 ? 4 : x==2 ? 4.5 : x==3 ? 5 : x==4 ? 2 : 1.5;
        cout << "Total: R$ " << fixed << setprecision(2) << y*price << endl;
    }
}
