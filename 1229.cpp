//1229
//Sub-Dictionary
//Graphs;Strongly Connected Components
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <algorithm>
#define MAX 101
using namespace std;

map<string, int> P;
int word(const string& p) {
    if (P.find(p) != P.end())
        return P[p];
    else
        return P[p] = P.size();
}

int O[MAX], npv, CO[MAX], GR[MAX];
string W[MAX];
bool G[MAX][MAX], V[MAX];
int n;
set<int> words;
set<string> answer;

void DFS(int v){
    V[v] = true;
    for(int i = 1; i <= n; i++)
        if (G[v][i] && !V[i])
            DFS(i);
    O[npv++] = v;
}

int DFSt(int v, int comp){
    int acum = 1;
    V[v] = true; CO[v] = comp;
    for(int i = 1; i <= n; i++)
       if (G[i][v] && !V[i])
            acum += DFSt(i, comp);
    return acum;
}

void DFSf(int v){
    V[v] = true;
    answer.insert(W[v]);
    for(int i = 1; i <= n; i++)
        if (G[v][i] && !V[i])
            DFSf(i);
}

int main() {
    string s, p, q;
    while(cin >> n, n) {
        memset(G, 0, sizeof(G));
        memset(CO, 0, sizeof(CO));
        memset(GR, 0, sizeof(GR));
        P.clear();
        words.clear();
        answer.clear();
        getline(cin, p);

        for(int i=0;i<n; i++) {
            getline(cin, s);
            stringstream sin(s);
            sin >> p;
            while(sin >> q) {
                G[word(p)][word(q)] = true;
                GR[word(p)]++;
            }
            W[word(p)] = p;
        }
        
        npv = 1;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));

        for(int i = 1; i <= n; i++)
            if(!V[i]) DFS(i);

        memset(V, 0, sizeof(V));

        int comp = 0;
        for(int i = n; i > 0; i--) {
            if(!V[O[i]]) {
                comp++;
                if (DFSt(O[i], comp) > 1 || GR[O[i]] == 0) {
                    for(int j=1;j<=n;j++) {
                        if (CO[j] == comp) {
                            words.insert(j);
                        }
                    }
                }
            }
        }

        memset(V, 0, sizeof(V));
        for(set<int>::iterator it=words.begin(); it!=words.end(); it++) {
            DFSf(*it);
        }
        
        cout << answer.size() << endl;
        for(set<string>::iterator it=answer.begin(); it!=answer.end(); it++)
            cout << (it!=answer.begin()?" ":"") << *it;
        cout << endl;
    }

    return 0;
}
