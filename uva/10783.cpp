//10783
//Odd Sum
//Misc;Ad hoc
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++) {
        int a, b;
        cin >> a >> b;
        int s = 0;
        for(int i=a;i<=b;i++) {
            if (i&1)
                s+=i;
        }
        cout << "Case " << tt << ": " << s << endl;
        
    }
}
