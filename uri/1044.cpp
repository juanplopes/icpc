//1044
//Multiples
//Misc;Beginner
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b) {
        if (a%b==0 || b%a==0) {
            cout << "Sao Multiplos" << endl;
        } else {
            cout << "Nao sao Multiplos" << endl;
        }
    }
}
