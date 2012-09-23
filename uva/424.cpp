//424
//Integer Inquiry
//Math;Big Integer
#define MAX 110
#include <iostream>
#include <string>
using namespace std;

int T[MAX];
int n=0;

void add(string& s) {
    int c=0;
    int m = s.size();
    for(int i=0; i<m; i++) {
        int a = s[m-i-1]-'0';
        T[i] += a+c;
        c = T[i]/10;
        T[i] %= 10;
    }
    n = max(n, m);
    while (c) {
        T[m] += c;
        c = T[m]/10;
        T[m] %= 10;
        n = max(n, ++m);
    }

}

int main() {
    string s;
    while(cin >> s, s!="0")
        add(s);

    for(int i=n-1; i>=0; i--)
        cout << T[i];
    cout << endl;
}

