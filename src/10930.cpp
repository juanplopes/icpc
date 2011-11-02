//10930
//A-Sequence
//Dynamic Programming;Knapsack;Binary Knapsack
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int K[30001];

int main() {
    int n, t=0, w;
    while(t++, cin >> n) {
        cout << "Case #" << t << ":";
        memset(K, 0, sizeof(K));

        bool ok=true;

        K[0] = 1; int last = 0;
        for(int i=1; i<=n; i++) {
            cin >> w; cout << " " << w;
            ok &= !K[w] && w > last;
            for(int j=10000; j>=w; j--)
                if (K[j-w])
                    K[j] = 1;
            last = w;
        }
        cout << endl;
        cout << "This is" << (ok?"":" not") << " an A-sequence." << endl;
    }

    return 0;
}
