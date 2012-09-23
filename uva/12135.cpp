//12135
//Switch Bulbs
//Graphs;Shortest Path;BFS
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX 33000
using namespace std;

vector<int> G[MAX];
int V[MAX];

int n, m;
struct Step {
    int x, w;
    Step() {}
    Step(int x, int w) : x(x), w(w) {}
};

int main() {
    int t; cin >> t; int tt=0;
    while(cin >> n >> m, t--) {
        memset(G, 0, sizeof(G));
        memset(V, -1, sizeof(V));

        n = 1<<n;

        for(int i=0; i<m; i++) {
            int a, b, mask=0;
            cin >> a;
            while(a--) {
                cin >> b;
                mask = mask | (1<<b);
            }
            for(int i=0; i<n; i++)
                G[i].push_back(i^mask);
        }
        
        queue<Step> Q;
        Q.push(Step(0, 0));
        while(!Q.empty()) {
            Step step = Q.front(); Q.pop();
            if (V[step.x] >= 0) continue;
            
            V[step.x] = step.w;
            for(int i=0; i<G[step.x].size(); i++)
                Q.push(Step(G[step.x][i], step.w+1));
        }
        
        cout << "Case " << ++tt << ":" << endl;
        int q; string s;
        cin >> q;
        while(q--) {
            int b = 0;
            cin >> s;
            for(int i=0; i<s.size(); i++)
                b = b*2 + (s[i]-'0');
            
            cout << V[b] << endl;
        }
        cout << endl;
    }
    
}
