#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#define MAX 400
using namespace std;

char G[MAX][MAX];
int B[MAX];
int n, m;

bool finishLine(const string& s) {
    for(int i=0;i<s.size(); i++)
        if (s[i] != '_' && s[i] != ' ') return false;
    return s.size() > 0;
}

bool dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (G[x][y] != ' ') return G[x][y] !='_' && G[x][y]!='#';
    
    G[x][y] = '_';
    bool should = dfs(x+1, y) | dfs(x-1, y) | dfs(x, y+1) | dfs(x, y-1);
    if (should) G[x][y] = '#'; 
    return false;
}

int main() {
    string s;
    int t; cin >> t; getline(cin, s);
    
    while(t--) {
        int sx, sy;
        memset(G, ' ', sizeof(G));
        n = m = 0;
        while(getline(cin, s) && !finishLine(s)) {
            m = max(m, (int)s.size()+1);
            for(int i=0;i<s.size();i++) {
                if (s[i] == '*') {
                    sx = n; sy = i;
                    continue;
                }
                G[n][i] = s[i];
            }
            n++; 
        }
        dfs(sx, sy);
        
        for(int i=0;i<n;i++) {
            B[i] = 0;
            for(int j=0;j<m;j++)
                if (G[i][j] != '_' && G[i][j] != ' ') 
                    B[i] = j+1;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<B[i];j++) {
                cout << (G[i][j]=='_'?' ':G[i][j]);
            }
           // cout << "^";
            cout << endl;
        }
        cout << s << endl;
    }
}
