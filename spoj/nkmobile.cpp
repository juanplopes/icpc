//NKMOBILE
//IOI01 Mobiles
//Misc;Fenwick Tree;2D
#include <iostream>
#include <cstring>
#define MAX 1030
using namespace std;

struct Fenwick2D {
    int T[MAX][MAX];
    int n, m;

    void clear(int n, int m) {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                T[i][j] = 0;
                
        this->n = n;
        this->m = m;
    }
    
    void adjust(int x, int y, int v) {
        for (int i=x; i <= n; i += (i&-i)) 
            for(int j=y; j <= m; j += (j&-j))
                T[i][j] += v; 
    }
    
    int rsq(int x, int y) {                   
        int sum = 0; 
        for(int i=x; i; i -= (i&-i))
            for(int j=y; j; j -= (j&-j))
                sum += T[i][j];
        return sum; 
    }

    int rsq(int x1, int y1, int x2, int y2) {            
        return rsq(x2, y2) - rsq(x2, y1-1) - rsq(x1-1, y2) + rsq(x1-1, y1-1); 
    }
};

Fenwick2D T;

int main() {
    int cmd;
    while(cin >> cmd, cmd != 3) {
        if (cmd == 0) {
            int s; 
            cin >> s;
            T.clear(s, s);
        } else if (cmd == 1) {
            int x, y, a;
            cin >> x >> y >> a;
            x++; y++;
            T.adjust(x, y, a);
        } else if (cmd == 2) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++; y1++; x2++; y2++;
            cout << T.rsq(x1, y1, x2, y2) << endl;
        }
    }
}
