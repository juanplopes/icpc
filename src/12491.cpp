//12491
//Words
//Misc;STL map
#include <iostream>
#include <string>
#include <map>
#include <set>
#define mit multimap<string, string>::iterator
#define mmit pair<multimap<string, string>::iterator,multimap<string, string>::iterator>
using namespace std;

multimap<string, string> X[2];
set<string> S[2], E[2];
char T[1000];

bool backtrack(int x, int k, int n) {
    string suffix(T+k, n-k);
    if (S[x].find(suffix) != S[x].end()) return false;
    S[x].insert(suffix);

    for(int s=1; s<=suffix.size(); s++) {
        string word = suffix.substr(0, s);
        
        for(int i=0; i<word.size(); i++)
            T[k+i] = word[i];
        
        if (E[x].find(word) != E[x].end()) {
            if (k + word.size()==n) return true;
            if (backtrack(x, k+word.size(), n)) return true;
        }
 
    }

    mmit ret = X[x].equal_range(suffix);
    for(mit it=ret.first;it != ret.second;it++) {
        string word = it->second;
        for(int i=0; i<word.size(); i++)
            T[k+i] = word[i];
        
        if (k + word.size() == n) return true;
        if (backtrack(1-x, n, k+word.size())) return true;
    }
    return false;
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        E[0].clear(); E[1].clear();
        X[0].clear(); X[1].clear();
        S[0].clear(); S[1].clear();
        for(int i=0; i<a; i++) {
            string s; cin >> s;
            for(int j=0;j<=s.size(); j++) {
                E[0].insert(s);
                X[0].insert(pair<string, string>(s.substr(0, j), s));
            }
        }
        for(int i=0; i<b; i++) {
            string s; cin >> s;
            for(int j=0;j<=s.size(); j++) {
                E[1].insert(s);
                X[1].insert(pair<string, string>(s.substr(0, j), s));
            }
        }
        cout << (backtrack(0,0,0) || backtrack(1,0,0) ? 'S' : 'N') << endl;
    }
    
}
