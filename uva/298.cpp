//298
//Race Tracks
//Graphs;Shortest Path;BFS
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 30
using namespace std;

bool V[MAX][MAX][7][7];
int X, Y;

struct Step {
    int x, y, a, b, v;
    Step() {}
    Step(int x, int y, int a, int b, int v) : x(x), y(y), a(a), b(b), v(v) {}
    
    bool valid() {
        return x>=0 && x<X && y>=0 && y<Y && a >= -3 && a <= 3 && b >= -3 && b <= 3 && !V[x][y][a+3][b+3];
    }

    void mark() {
        V[x][y][a+3][b+3] = true;
    }
    
    Step go(int mx, int my) {
        return Step(x+a+mx, y+b+my, a+mx, b+my, v+1);
    }
};

int main() {
    int t; cin >> t; t=0;
    while(cin >> X >> Y) {
        memset(V, 0, sizeof(V));
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int p, px1, px2, py1, py2;
        cin >> p;
        while(p--) {
            cin >> px1 >> px2 >> py1 >> py2;
            for(int i=px1; i<=px2; i++)
                for(int j=py1; j<=py2; j++)
                    for(int ai=0; ai<=6; ai++)
                        for(int bi=0; bi<=6; bi++)
                            V[i][j][ai][bi] = true;
        }
        
        bool found = false;
        queue<Step> Q;
        Q.push(Step(x1, y1, 0, 0, 0));
        
        while(!Q.empty()) {
            Step it = Q.front(); Q.pop();
            if (!it.valid()) continue;
            it.mark();
            
            if (it.x == x2 && it.y == y2) {
                cout << "Optimal solution takes " << it.v << " hops." << endl;
                found = true;
                break;
            }
            
            for(int ai=-1; ai<=1; ai++)
                for(int bi=-1; bi<=1; bi++)
                    Q.push(it.go(ai, bi));
        }
        if (!found) cout << "No solution." << endl;
    }
}
