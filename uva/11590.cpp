//11590
//Prefix Lookup
//Misc;String Matching;Trie
#include <iostream>
#include <cstring>
#define MAXS 1500010
#define ull unsigned long long
using namespace std;

struct Trie {
    int G[MAXS][2];
    ull S[MAXS];
    bool E[MAXS];
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
        E[state] = false;
        return state;
    }
    
    void add(string &s) {
        int state = 0;
        for(int i=0; i<s.size()-1; i++) {
            S[state]++;

            int next = s[i] - '0';

            if (G[state][next] < 0)
                G[state][next] = clear(stateCount++);

            state = G[state][next];
        }
        E[state] = true;
    }
};

Trie T;

ull dfs(int state, int depth) {
    ull s = 0;

    for (int e = 0; e < 2; ++e) {
        if (T.G[state][e] == -1) continue;
        
        s += dfs(T.G[state][e], depth-1);
    }

    T.S[state] = s;   
   
    return T.E[state] ? 1ull << depth : s;
}


ull answer(string &s, int m) {
    int state = 0;
    for(int i=0; i<s.size()-1; i++) {
        int next = s[i]-'0';
        state = T.G[state][next];
    }
    int shift = m-s.size()+1;
    ull base = shift == 64 ? 0 : 1ull << shift;
    return base - T.S[state];
}

int main() {
    int n, m, q;
    while(cin >> n >> m, n|m) {
        T.clear();
        
        for(int i=0; i<n; i++) {
            string s; cin >> s;
            T.add(s);
        }
        
        dfs(0, m); 
        
        cin >> q;
        for(int i=0; i<q; i++) {
            string s; cin >> s;
            cout << answer(s, m) << endl;
        }
        cout << endl;
    }
}
