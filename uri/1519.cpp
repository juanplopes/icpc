//1519
//Abbreviations
//Misc;STL map
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Word {
    string w;
    int c;
    
    Word(string w, int c) : w(w), c(c) {}
    
    inline bool operator <(const Word& o) const {
        return c > o.c;
    }
};


vector<string> W;
vector<Word> WW;
map<string, char> M;
map<char, string> RM;
map<string, int> C;


int main() {
    string s;
    while(getline(cin, s), s!=".") {
        W.clear();
        M.clear();
        C.clear();
        WW.clear();
        RM.clear();
        
        stringstream sin(s);
        string word;
        while(sin >> word) {
            if (C.find(word) == C.end()) C[word] = 0;
            C[word] += word.size()-2;

            W.push_back(word);
        }
        
        for(map<string, int>::iterator it = C.begin(); it != C.end(); it++) {
            WW.push_back(Word(it->first, it->second));
        }
        
        sort(WW.begin(), WW.end());
        
        for(int i=0; i<WW.size(); i++) {
            char letter = WW[i].w[0];
            if (WW[i].c <= 0 || RM.find(letter) != RM.end()) continue;
            
            M[WW[i].w] = letter;
            RM[letter] = WW[i].w;
        }
        
        for(int i=0; i<W.size(); i++) {
            if (i>0) cout << " ";
            
            if (M.find(W[i]) != M.end()) {
                cout << M[W[i]] << ".";
            } else {
                cout << W[i];
            }
        }
        cout << endl;
        
        cout << M.size() << endl;
        for(map<string, char>::iterator it = M.begin(); it != M.end(); it++) {
            cout << it->second << ". = " << it->first << endl;
        }
    }
}

