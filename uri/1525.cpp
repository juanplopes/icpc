//1525
//Gruntz
//Graphs;Shortest Path;BFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char M[110][110];
int V[110][110];
int n, m, k;


struct Move {
    int x, y, c;
    Move(int x, int y, int c) : x(x), y(y), c(c) {}
};

queue<Move> Q;

char inv(char c) {
    if (c=='<') return '>';
    if (c=='>') return '<';
    if (c=='^') return 'v';
    if (c=='v') return '^';
}

inline void put(int x, int y, int c, char expected) {
    if (x<0 || x>=n || y<0 || y>=m)
        return;
    if (M[x][y] == expected && c < V[x][y]) {
        Q.push(Move(x, y, c));
        V[x][y] = c;
    } else if (M[x][y] == inv(expected) && c+1 <= k && c < V[x][y]) {
        Q.push(Move(x, y, c+1));
        V[x][y] = c+1;
    }
}

inline  bool test(int x, int y) {
    for(int i=0; i<=k; i++) {
        if (V[x][y] <= k) {
            return true;
        }
    }
    return false;
}

int main() {
    while(scanf("%d %d %d", &n, &m, &k), n|m|k) {
        memset(V, 0x3f, sizeof(V));
        int si, sj;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> M[i][j];
                if (M[i][j] == 'x') { si = i, sj = j; };
            }
        }

        put(si, sj, 0, 'x');        
        while(Q.size() > 0) {
            Move move = Q.front(); Q.pop();
            
            put(move.x-1, move.y, move.c, 'v');
            put(move.x+1, move.y, move.c, '^');
            put(move.x, move.y-1, move.c, '>');
            put(move.x, move.y+1, move.c, '<');
        }
        
        bool A = false;
        for(int i=0; i<n; i++) {
            A |= test(i, 0);
            A |= test(i, m-1);
        }
        for(int i=0; i<m; i++) {
            A |= test(0, i);
            A |= test(n-1, i);
        }
        cout << (A?"Sim":"Nao") << endl;
    }
}

