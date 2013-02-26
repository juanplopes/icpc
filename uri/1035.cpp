//1035
//Selection Test 1
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        if (b>c and d>a and c+d>a+b and c>0 and d>0 and a%2==0) 
            cout << "Valores aceitos" << endl;
        else
            cout << "Valores nao aceitos" << endl;
        
        
    }
}
