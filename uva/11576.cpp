//11576
//Scrolling Sign
//Misc;String Matching;KMP;Suffix-Prefix
#include <iostream>
#include <string>
#include <cstring>
#define MAX 100010
using namespace std;

int F[MAX];

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

int kmp(string& P, string& T) {
    kmp_init(P);
    int i = 0, j = 0;
    int n = T.size(), m = P.size();
    
    while(i < n) {
        while(j < m) {
            if (P[j] == T[i]) {
                i++; j++;
            } else break;
        }
        if (j == 0) i++;
        if (i==n) return j;
        j = F[j];
    }
    return 0;
}


int main() {
    int t; cin >> t; t=0;
    int k, w;
    while(cin >> k >> w) {
        int sum = 0;
        string Q, P = "";
        while(w--) {
            cin >> Q;
            sum += k-kmp(Q, P);
            P = Q;
        }
        cout << sum << endl;
    }
}
