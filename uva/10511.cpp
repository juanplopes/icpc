//10511
//Councilling
//Graphs;Maximum Flow;Ford-Fulkerson
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#define MAX 1300
using namespace std;

int G[MAX][MAX], n;
bool V[MAX];
map<string, int> EC, EP, EM;

int SOURCE() { return 1; }
int P(string& s) { if (EP.find(s)!=EP.end()) return EP[s]; else { return EP[s]=++n;} }
int M(string& s) { if (EM.find(s)!=EM.end()) return EM[s]; else { return EM[s]=++n;} }
int C(string& s) { if (EC.find(s)!=EC.end()) return EC[s]; else { return EC[s]=++n;} }
int TARGET() { return 2; }

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    for(int i=1; i<=n; i++) {
        if (!V[i] && G[s][i] > 0) {
            if (int sent = send(i, t, min(minn, G[s][i]))) {
                G[s][i] -= sent;
                G[i][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

int main() {
    int t; cin >> t;
    string s, sm, sp, sc;
    getline(cin, s); getline(cin, s);
    while(t--) {
        EC.clear(); EP.clear(); EM.clear();
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        n=2;
        
        while(getline(cin, s) && s!="" && s!=" ") {
            stringstream sin(s);
            sin >> sm >> sp;
            G[P(sp)][M(sm)] = 1;
            while(sin >> sc) {
                G[M(sm)][C(sc)] = 1;
                G[C(sc)][TARGET()] = 1;
            }   
        }
        
        int maxParty = (EC.size()-1)/2;
        for(map<string, int>::iterator it=EP.begin(); it!=EP.end(); it++) {
            G[SOURCE()][it->second] = maxParty;
        }
        
        
        int total = 0;
        while(int sent = send(SOURCE(), TARGET(), INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        
        if (total == EC.size()) {
            for(map<string, int>::iterator i=EM.begin(); i!=EM.end(); i++) {
                for(map<string, int>::iterator j=EC.begin(); j!=EC.end(); j++) {
                    if (G[j->second][i->second]) {
                        cout << i->first << " " << j->first << endl;
                    }
                }
            }
        } else {
            cout << "Impossible." << endl;
        }
        
        if (t) cout << endl;
    }
}
