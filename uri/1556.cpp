//1556
//Removing Letters
//Misc;Backtracking
#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> A;
string S;
int N[2000];
char T[2000];

void generate(int t, int k) {
    if (k==S.size()) {
        if (t!=0)
            A.insert(string(T, t));
    } else {
        generate(t, N[k]);
        for(int i=k; i<N[k]; i++) {
            T[t++] = S[i];
            generate(t, N[k]);
        }
    }
}

int main() {
    while(cin >> S) {
        int nextK = S.size();
        for(int i=S.size()-1; i>=0; i--) {
            N[i] = nextK;
            if (i>0 && S[i]!=S[i-1])
                nextK = i;
        }
        
        A.clear();
        generate(0, 0);
        for(set<string>::iterator it=A.begin(); it!=A.end(); it++)
            cout << *it << endl;
        cout <<endl;
    }
}
