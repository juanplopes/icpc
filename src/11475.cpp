//11475
//Extend to Palindrome
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
    string S, P, T;
    while(cin >> S) {
        P = string(S.rbegin(), S.rend());
        
        string K = S.substr(0, S.size()-kmp(P, S));

        cout << S+string(K.rbegin(), K.rend()) << endl;
    }
}
