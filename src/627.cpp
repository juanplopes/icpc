//627
//The Net
//Graphs;Shortest Path;BFS
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#define MAX 400
using namespace std;

int G[MAX][MAX], n, m;
bool V[MAX];


struct Step {
    int x, v, p;
    Step() {}
    Step(int x, int v, int p) : x(x), v(v), p(p) {}
};

vector<Step> Q;

void print(Step step, bool first) {
    if (step.p != -1) print(Q[step.p], false);
    cout << step.x << (first?"":" ");
}

int main() {
    while(cin >> n) {
        cout << "-----" << endl;
        memset(G, 0, sizeof(G));

        int a, b;
        for(int i=0; i<n;i++) {
            cin >> a;
            while(cin.get()!='\n') {
                if (cin.peek() == '\n') break;
                cin >> b;
                G[a][b] = true;
            }        
        }

        cin >> m;
        for(int i=0;i<m;i++) {
            memset(V, 0, sizeof(V));
            cin >> a >> b;
            Q = vector<Step>();
            Q.push_back(Step(a, 0, -1));
            
            int ptr = 0;
            while(ptr < Q.size()) {
                Step it = Q[ptr];
                if (it.x == b) {
                    print(it, true);
                    cout << endl;
                    break;
                }
                
                if (V[it.x]) { ptr++; continue; }
                V[it.x] = true;
                
                for(int i=1; i<=n; i++)
                    if (G[it.x][i]) Q.push_back(Step(i,it.v+1,ptr));
                
                ptr++;
            }
            if (ptr == Q.size()) cout << "connection impossible" << endl;
        }
    }
}
