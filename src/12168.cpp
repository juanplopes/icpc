//12168
//Cat vs. Dog
//Graphs;Bipartite Matching;Konig Theorem
#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#define MAX 505
using namespace std;

string V1[MAX], V2[MAX];
int G[MAX][MAX], n;
bool V[MAX];

int send(int s, int t, int minn) {
    V[s] = true;

    if (s==t) return minn;
    for(int i=0; i<=n; i++) {
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
    int c, d, v;

    while(cin >> c >> d >> v, t--) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));

        string s1, s2;
        for(int i=1; i<=v; i++) {
            cin >> s1 >> s2;
            V1[i] = s1; V2[i] = s2;
            
            bool dog = s1[0] == 'D';
            
            if (dog)
                G[0][i] = 1;
            else
                G[i][v+1] = 1;
                
            for(int j=1; j<i; j++) {
                if (s1 == V2[j] || s2 == V1[j]) 
                    if (dog)
                        G[i][j] = 1;
                    else 
                        G[j][i] = 1;   
            }
        }
        n = v+1;
        
        int total = 0;
        while(int sent = send(0, n, INT_MAX)) {
            total += sent;
            memset(V, 0, sizeof(V));
        }
        cout << v-total << endl;
    }

    return 0;
}
