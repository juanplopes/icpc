//10035
//Primary Arithmetic
//Misc;Ad hoc
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b, a|b) {
        int carries = 0;
        int c = 0;
        while(a|b) {
            int s = a%10 + b%10 + c;
            c = s/10;
            if (c) carries++;
            
            a/=10; 
            b/=10;
        }
        
        if (carries == 0) {
            cout << "No carry operation." << endl;
        } else if (carries==1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carries << " carry operations." << endl;
        }
    }
}
