//1213
//Sum of Different Primes
//Dynamic Programming;Knapsack;Counting Knapsack
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long K[20][1300];
bool P[1300];
vector<int> W();

int main() {
    int n, k; 
    
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for(int i=2; i<1300; i++) {
        if (P[i]) {
            W.push_back(i);
            for(int j=i*i; j<1300; j+=i)
                P[j] = false;
        }
    }

    K[0][0] = 1;
    for(int i=0; i<W.size(); i++)
        for(int p=19; p>0; p--)
            for(int j = W[i]; j<1300; j++)
                K[p][j]+=K[p-1][j-W[i]];        
    
    while(cin >> n >> k, n|k)
        cout << K[k][n] << endl;
}
