//422
//Word-Search Wonder
//Misc;String Matching;KMP;2D
#include <iostream>
#include <string>
#include <cstring>
#define MAX 105
using namespace std;

char C[MAX][MAX];
int F[MAX];
int n;

void kmp_init(string& P) {
    F[0] = 0;  F[1] = 0;  
    int i = 1, j = 0;
    while(i<P.size()) {
        if (P[i] == P[j])
            F[++i] = ++j;
        else if (j == 0)
            F[++i] = 0;
        else
            j = F[j];
    }
}

bool kmp(string& P, int x, int y, int mx, int my) {
    kmp_init(P);
    int j = 0, m = P.size();
    
    while(x >= 0 && x < n && y >= 0 && y < n) {
        while(j < m) {
            if (P[j] == C[x][y]) {
                x+=mx; y+=my; j++;
            } else break;
        }
        if (j == m) { 
            cout << x-m*mx+1 << "," << y-m*my+1 << " " << x+1-mx << "," << y+1-my << endl;
            return true;
        }
        else if (j == 0) { x+=mx; y+=my; };
        j = F[j];
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> C[i][j];

    string P;
    while(cin >> P, P!="0") {
        bool result = false;
        for(int i=0; i<n; i++) {
            result = result || kmp(P, i,   0,    0,  1);
            result = result || kmp(P, i,   n-1,  0, -1);
            result = result || kmp(P, 0,   i,    1,  0);
            result = result || kmp(P, n-1, i,   -1,  0);

            result = result || kmp(P, 0,   i,    1,  1);
            result = result || kmp(P, i,   n-1, -1, -1);
            result = result || kmp(P, i,   0,    1,  1);
            result = result || kmp(P, n-1, i,   -1, -1);
            
            result = result || kmp(P, 0,   i,   -1,  1);
            result = result || kmp(P, i,   0,    1, -1);
            result = result || kmp(P, i,   n-1,  1, -1);
            result = result || kmp(P, n-1, i,   -1,  1);
        }

        if (!result)
            cout << "Not found" << endl;
    }
}
