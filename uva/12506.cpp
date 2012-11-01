//12506
//Shortest Names
//Misc;String Matching;Trie
#include <iostream>
#include <cstring>
#define MAXS 1000010
using namespace std;

struct Trie {
    int G[MAXS][26];
    int S[MAXS];
    int stateCount;
    
    Trie() {
        clear();
    }
    
    void clear() {
        stateCount = 0;
        clear(stateCount++);
    }
    
    int clear(int state) {
        memset(G[state], -1, sizeof G[state]);
        S[state] = 0;
        return state;
    }
    
    void add(string &s) {
        int state = 0;
        for(int i=0; i<s.size(); i++) {
            S[state]++;

            int next = s[i] - 'a';

            if (G[state][next] < 0)
                G[state][next] = clear(stateCount++);

            state = G[state][next];
        }
    }
};

Trie T;

int dfs(int state) {
    if (T.S[state] == 1) return 0;

    int s = T.S[state];

    for (int e = 0; e < 26; ++e) {
        if (T.G[state][e] == -1) continue;
        
        s += dfs(T.G[state][e]);
    }
    
    return s;
}


int main() {
    int tt; cin >> tt;
    while(tt--) {
        T.clear();
        
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            string s; cin >> s;
            T.add(s);
        }
        
        cout << dfs(0) << endl;
    }
}
