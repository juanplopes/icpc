#include <iostream>
using namespace std;

long gcd(long a, long b) {
    if (a==-1) return b;
    while(b) {
        long c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int t; cin >> t; t--;
    int n;
    while(cin >> n) {
        long result = -1;
        for(int i=0; i<n; i++) {
            long s=0, tmp;
            for(int j=0; j<9; j++) {
                cin >> tmp; s+=tmp;
            }
            cin >> tmp; s -= tmp;
            //cout << "*" << s << endl;
            result = gcd(result, s);
        }
        if (result>1) 
            cout << result << endl;
        else
            cout << "impossible" << endl;
    }
}
