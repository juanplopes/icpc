//12184
//Transcribed Books
//Math;GCD
#include <iostream>
using namespace std;

long gcd(long a, long b) {
    while(b) {
        long c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int t; cin >> t;
    int n;
    while(cin >> n) {
        long result = 0;
        long maxSerial = 0;
        for(int i=0; i<n; i++) {
            long s=0, tmp;
            for(int j=0; j<9; j++) {
                cin >> tmp; s+=tmp;
            }
            cin >> tmp; 
            s -= tmp;
            maxSerial = max(maxSerial, tmp);
            result = gcd(result, s);
        }
        if (result>1 && maxSerial < result)  
            cout << result << endl;
        else
            cout << "impossible" << endl;
    }
}
