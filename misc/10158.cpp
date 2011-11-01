//10158
//War
//Misc;Union-Find
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int P[20000];

inline int enemy(int v) { return v+10000; }

inline int findset(int v) {
    if (P[v] != -1 && P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    P[b] = a;
}

int main() {
    memset(P, -1, sizeof(P));
    int n, c, x, y;
    cin >> n;
    while(cin >> c >> x >> y, c|x|y) { 
        if (c==1) {
            if (findset(x) == findset(enemy(y))) { cout << -1 << endl; continue; }
            unionset(x, y);
            unionset(enemy(x), enemy(y));
        } else if (c==2) {
            if (findset(x) == findset(y)) { cout << -1 << endl; continue; }
            unionset(x, enemy(y));
            unionset(enemy(x), y);
        } else if (c==3) {
            cout << (findset(x) == findset(y)) << endl;
        } else if (c==4) {
            cout << (findset(x) == findset(enemy(y))) << endl;
        }
    }
}
