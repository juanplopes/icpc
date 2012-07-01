//591
//Box of Bricks
//Misc;Ad hoc
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int T[100];

int main() {
    int n, t=0;
    while(cin >> n, n) {
        int s=0;
        for(int i=0; i<n; i++) {
            cin >> T[i];
            s += T[i];
        }
        s/=n;
        
        int r=0;
        for(int i=0; i<n; i++) {
            r+=abs(T[i]-s);
        }
        cout << "Set #" << ++t << endl;
        cout << "The minimum number of moves is " << r/2 << "." << endl;
        cout << endl;
    }
}
