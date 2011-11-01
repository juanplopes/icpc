//10051
//Tower of Cubes
//Dynamic Programming;Longest Increasing Subsequence
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX 501
#define MAXC 101
using namespace std;

int T[MAX][MAXC], F[MAX][MAXC], P[MAX][MAXC];
int A[6];

string translate(int side) {
    switch(side) {
        case 0: return "front";
        case 1: return "back";
        case 2: return "left";
        case 3: return "right";
        case 4: return "top";
        case 5: return "bottom";
    }
}

void print(int first, int k) {
    if (k==0) return;
    
    print(F[k][first], k-1);
    cout << T[k][first] << " " << translate(P[k][first]) << endl;
}

int main() {
    int n, n2, t;
    while(cin >> n, n) {
        if (t++) cout << endl;
        cout << "Case #" << t << endl;
        
        memset(T, 0, sizeof(T));

        for(int i=1;i<=MAXC; i++) {
            T[0][i] = 1;
        }
        int k = 0;
        
        for(int cube=1;cube<=n;cube++) {
            for(int i=0;i<6;i++) cin >> A[i];
            int newk = k;
            for(int j=k; j>=0; j--) {
                for(int i=0;i<6;i++) {
                    int other = (i/2*2)+(1-i%2);
                    if (T[j][A[i]] && !T[j+1][A[other]]) {
                        T[j+1][A[other]] = cube;
                        F[j+1][A[other]] = A[i];
                        P[j+1][A[other]] = i;
                        newk = max(newk, j+1);
                    }
                }
            }
            k=newk;
        }
        
        cout << k << endl;
        
        int first=0;
        for(int i=1;i<=100;i++)
            if (T[k][i]) first=i;
        
        print(first, k);
    }

    return 0;
}
