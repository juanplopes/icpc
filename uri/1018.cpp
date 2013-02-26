//1018
//Banknotes
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int note(int x, int note) {
    int n = 0;
    while(x >= note) {
        n+=1;
        x-=note;
    }
    cout << n << " nota(s) de R$ " << note << ",00" << endl;
    return x;
}

int main() {
    int x;
    while(cin >> x) {
        cout << x << endl;
        x = note(x, 100);
        x = note(x, 50);
        x = note(x, 20);
        x = note(x, 10);
        x = note(x, 5);
        x = note(x, 2);
        x = note(x, 1);
    }
}
