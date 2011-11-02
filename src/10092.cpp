//10092
//The Problem with the Problem Setter
//Graphs;Maximum Flow;Ford-Fulkerson
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#define MAX 1100
using namespace std;

int G[MAX][MAX], nk, np, n;
bool V[MAX];

int SOURCE() { return 1; }
int P(int i) { return 1+i; }
int K(int i) { return 1+np+i; }
int TARGET() { return 2+np+nk; }

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
    int tmp, tmp2;
    while(cin >> nk >> np, nk|np) {
        n = nk+np+2;
        int expected = 0;
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        
        for(int i=1; i<=nk; i++) {
            cin >> tmp;
            expected += tmp;
            G[K(i)][TARGET()] = tmp;
        }
        
        for(int i=1;i<=np; i++) {
            cin >> tmp;
            G[SOURCE()][P(i)] = 1;
            for(int j=0;j<tmp;j++) {
                cin >> tmp2;
                G[P(i)][K(tmp2)] = 1;
            }
        }
        
        int total = 0;
        while(int sent = send(SOURCE(), TARGET(), INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        cout << (expected == total ? 1: 0) << endl;
        if (expected == total) {
            for(int i=K(1); i<=K(nk); i++) {
                bool printed = false;
                for(int j=P(1); j<=P(np); j++) {
                    if (G[i][j]) {
                        cout << (printed?" ":"") << (j-1);
                        printed = true;
                    }
                }
                cout << endl;
            }
        }
    }
}
