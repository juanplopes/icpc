//12148
//Electricity
//Misc;Ad hoc
#include <iostream>
using namespace std;

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool oneday(int ad, int am, int ay, int bd, int bm, int by) {
    if (--bd == 0) { 
        if (--bm == 0) {
            --by;
            bm=12;
        }
        
        bd = M[bm-1];
        
        bool isleap = (by%4==0 && (by%100!=0 || by%400==0));
        if (bm==2 && isleap) bd=29;
    }
    return ad==bd && am==bm && ay==by;
    
}

int main() {
    int n, ad=0, am=0, ay=0, ac=0;
    while(cin >> n, n) {
        int sum = 0, count=0;
        while(n--) {
            int bd, bm, by, bc;
            cin >> bd >> bm >> by >> bc;
            if (oneday(ad, am, ay, bd, bm, by)) {
                sum += bc-ac; count++;
            }
            ad = bd; am = bm; ay = by; ac = bc;
        }
        cout << count << " " << sum << endl;
    }

    return 0;
}
