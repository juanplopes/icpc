//119
//Greedy Gift Givers
//Misc;STL map
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, int> M;
vector<string> V;

int main() {
    int n, t=0;
    while(cin >> n) {
        M.clear(); V.clear();
        if (t++) cout << endl;
        
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            M[s] = 0;
            V.push_back(s);
        }
        
        for(int i=0; i<n; i++) {
            string a; int g, m;
            cin >> a >> g >> m;
            if (!m) continue;
            g /= m;
            
            for(int j=0; j<m; j++) {
                string b;
                cin >> b;
                M[b] += g;
                M[a] -= g;
            }
        }
        
        for(int i=0; i<n; i++)
            cout << V[i] << " " << M[V[i]] << endl;
    }
    
}
