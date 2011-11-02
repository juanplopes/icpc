//10298
//Power Strings
//Misc;String Matching;KMP
#include <iostream>
#include <string>
#include <cstring>
#define MAX 1000010
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

int kmp(string& P, string& T, int start) {
    kmp_init(P);
    int i = start, j = 0;
    int n = T.size(), m = P.size();
    
    while(i-j <= n-m) {
        while(j < m) {
            if (P[j] == T[i]) {
                i++; j++;
            } else break;
        }
        if (j == m) return i-m;
        else if (j == 0) i++;
        j = F[j];
    }
}


int main() {
    string P, T;
    while(cin >> P, P!=".") {
        T = P+P;
        cout << P.size() / kmp(P, T, 1) << endl;
    }
}
