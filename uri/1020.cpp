//1020
//Age in Days
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int x;
    while(cin >> x) {
        cout << x/365 << " ano(s)" << endl;
        cout << x%365/30 << " mes(es)" << endl;
        cout << x%365%30 << " dia(s)" << endl;
    }
}
