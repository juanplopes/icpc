//12155
//ASCII Diamondi
//Misc;Ad hoc
#include <iostream>
using namespace std;

inline int abs(int n) { return n>0?n:-n; }

inline char charAt(int n, int x, int y) {
    x%=n*2-1; y%=n*2-1;
    int dist = abs(n-x-1)+abs(n-y-1);
    if (dist < n)
        return (char)(dist%26+'a');
    else
        return '.';
}

int main() {
    int n, ax, ay, bx, by, t=0;
    while(cin >> n, n) {
        cin >> ax >> ay >> bx >> by;
        cout << "Case " << ++t << ":" << endl;
        for(int i=ax; i<=bx; i++) {
            for(int j=ay; j<=by; j++) {
                cout << charAt(n, i, j);
            }
            cout << endl;
        }
    }

}
