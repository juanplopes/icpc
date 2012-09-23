//1223
//Editor
//Dynamic Programming;Longest Common Substring
#include <iostream>
#include <string>
#include <cstring>
#define MAX 5001
using namespace std;

int T[MAX][MAX];

int main() {
    int t; cin >> t; t=0;
    string s;
    while(cin >> s) {
        int sz = s.size();
        int maxx = 0;
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                if (s[i-1] == s[j-1] && i!=j)
                    maxx = max(maxx, T[i][j] = T[i-1][j-1]+1);
                else
                    T[i][j] = 0;
            }
        }

        cout << maxx << endl;
    }

    return 0;
}

