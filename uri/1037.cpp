//1037
//Interval
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x;
    while(cin >> x) {
        if (x >= 0 && x<=25)
            cout << "Intervalo [0,25]" << endl;
        else if (x > 25 && x<=50)
            cout << "Intervalo (25,50]" << endl;
        else if (x > 50 && x<=75)
            cout << "Intervalo (50,75]" << endl;
        else if (x > 75 && x<=100)
            cout << "Intervalo (75,100]" << endl;
        else 
            cout << "Fora de intervalo" << endl;
    }
}
