//11703
//sqrt log sin
//Dynamic Programming;Ad hoc
#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

int K[1000001];

int main() {
    K[0] = 1;
    for(int i=1; i<1000001; i++) {
        int a = (int)(i-sqrt(i));
        int b = (int)log(i);
        int c = (int)(i*pow(sin(i), 2));
        K[i] = (K[a] + K[b] + K[c])%1000000;
    }

    int n;
    while(cin >> n, n>-1)
        cout << K[n] << endl;

    return 0;
}
