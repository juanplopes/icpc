//12160
//Unlock the Lock
//Graphs;Shortest Path;BFS
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

bool V[10000];
int R[10];

struct Step {
    int x, w;
    Step() {}
    Step(int x, int w) : x(x), w(w) {}
    
    Step sum(int n) {
        return Step((x+n)%10000, w+1);
    }
};

int main() {
    int a, b, n, t=0;
    while(cin >> a >> b >> n, a|b|n) {
        for(int i=0;i<n;i++)
            cin >> R[i];
        
        cout << "Case " << ++t << ": ";
        memset(V, 0, sizeof(V));
        queue<Step> Q;
        Q.push(Step(a, 0));
        bool found = false;
        while(!Q.empty()) {
            Step step = Q.front(); Q.pop();
            if (V[step.x]) continue;
            V[step.x] = true;
            if (step.x == b) {
                cout << step.w << endl;
                found = true;
                break;
            }
            for(int i=0;i<n;i++)
                Q.push(step.sum(R[i]));
        }
        if (!found) cout << "Permanently Locked" << endl;
    }
    
}
