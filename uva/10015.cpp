//10015
//Joseph's Cousin
//Dynamic Programming;Josephus Problem
#include <iostream>
#include <vector>
#define MAX 35000
#define MAX2 3503
using namespace std;

bool P[MAX];
vector<int> W;
int T[MAX2][MAX2];

int main() {
    P[0] = P[1] = true;
    for(int i=2; i<MAX; i++) {
        if (!P[i]) {
            W.push_back(i);
            for(int j=i*i; j<MAX; j+=i)
                P[j] = true;
        }
    }

    for(int i=2; i<MAX2; i++)
        for(int j=0; j<MAX2-1; j++)
            T[i][j] = (W[j] + T[i-1][j+1])%i;
    
    int n;
    while(cin >> n, n) {
        cout << T[n][0]+1 << endl;
    }

}
