//11658
//Best Coalitions
//Dynamic Programming;Knapsack;Binary Knapsack
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int K[10001], W[102];

int main() {
  int n, x, a, b;
 
  while(cin >> n >> x, n|x) {
    memset(K, 0, sizeof(K));
    
    for(int i=1; i<=n; i++) {
        cin >> a; cin.ignore(); cin >> b;
        W[i] = a*100+b;
    }
    
    K[W[x]] = 1;
    for(int i=1; i<=n; i++) {
        if (i==x) continue;
        for(int j=10000; j>=W[i]; j--)
            if (K[j-W[i]])
                K[j] = 1;
    }
   
    int maxx = 0;
    for(int i=5001; i<=10000; i++) {
        if (K[i]) {
            maxx = i;
            break;
        }
    }
    
    cout << fixed << setprecision(2) << (W[x]/((double)maxx)*100.0) << endl;
  }

  return 0;
}
