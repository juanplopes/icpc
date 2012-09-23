//321
//The New Villa
//Graphs;Shortest Path;BFS
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#define MAX 15
using namespace std;



int G[MAX][MAX], C[MAX][MAX], n, m1, m2;
bool V[MAX][1200];
string dir;
struct Step {
    int x, s, v, p;
    int type, room;
    Step() {}
    Step(int x, int s, int v, int p) : x(x), s(s), v(v), p(p) {}
    Step(int x, int s, int v, int p, int type, int room) : type(type), room(room), x(x), s(s), v(v), p(p) {}
    
    Step change(int pp, int i) {
        return Step(x, s ^ (1<<i), v+1, pp, (s & (1<<i))?2:1, i);
    }
    Step move(int pp, int i) {
        return Step(i, s, v+1, pp, 3, i);
    }
};

vector<Step> Q;

void print(Step step) {
        if (step.p == -1) return;
        print(Q[step.p]);
        if (step.type == 1)
            cout << "- Switch on light in room " << step.room+1 << "." << endl;
        if (step.type == 2)
            cout << "- Switch off light in room " << step.room+1 << "." << endl;
        if (step.type == 3)
            cout << "- Move to room " << step.room+1 << "." << endl;
    }



int main() {
    int tt=0;
    while(cin >> n >> m1 >> m2, n|m1|m2) {
        Q = vector<Step>();
        
        memset(G, 0, sizeof(G));
        memset(C, 0, sizeof(C));
        memset(V, 0, sizeof(V));
        
        int a, b;
        for(int i=0;i<m1; i++) {
            cin >> a >> b;
            a--; b--;
            G[a][b] = G[b][a] = 1;
        }
        for(int i=0;i<m2; i++) {
            cin >> a >> b;
            a--;b--;
            C[a][b] = 1;
        }
        
        Q.push_back(Step(0, 1, 0, -1));
        
        int ptr = 0;
        cout << "Villa #" << ++tt << endl;
        while(ptr < Q.size()) {
            Step it = Q[ptr];
            if (it.x == n-1 && it.s == (1<<(n-1))) {
                cout << "The problem can be solved in " << it.v << " steps:" << endl;
                print(it);
                break;
            }
            
            if (V[it.x][it.s]) { ptr++; continue; }
            V[it.x][it.s] = true;
            
            for(int i=0; i<n; i++) {
                if (G[it.x][i] && (it.s & (1<<i))) Q.push_back(it.move(ptr, i));
                if (C[it.x][i] && it.x != i) Q.push_back(it.change(ptr, i));
            }
            
            ptr++;
        }
        if (ptr == Q.size()) cout << "The problem cannot be solved." << endl;
        cout << endl;
    }
}
