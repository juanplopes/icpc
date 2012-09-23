//1017
//Staircases
//Dynamic Programming;Ad hoc
#include <iostream>
#define MAX 506
using namespace std;

long long T[MAX][MAX];

int main() {
    for(int i=1;i<MAX; i++) {
        for(int j=1; j<=i; j++) {
            T[i][j] = 1;
            for(int k=j; k<=i; k++)
                T[i][j] += T[i-k][k+1];
        }
    }

    int n;
    while(cin >> n)
        cout << T[n][1]-1 << endl;
}
