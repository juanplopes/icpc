//652
//Eight
//Graphs;Shortest Path;BFS
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct Item {
    int p, x;
    string v;
    char m;

    Item() { }
    Item(int p, string v, int x, char m) : p(p), v(v), x(x), m(m) { }
};

map<string, int> M;
Item Q[400000];
int qq=0;

void add(int p, string v, int i, int j, char m) {
    if (not (i%3 == j%3 ^ i/3 == j/3) || j<0 || j>=9) return;
    swap(v[i], v[j]);
    if (M.find(v) != M.end()) return;    
    Q[M[v]=qq++] = Item(p, v, j, m);
}

int main() {
    Q[M["123456780"]=qq++] = Item(-1, "123456780", 8, 'z');
    
    for(int i=0; i<qq; i++) {
        Item p = Q[i];
        
        add(i, p.v, p.x, p.x-1, 'r');
        add(i, p.v, p.x, p.x+1, 'l');
        add(i, p.v, p.x, p.x-3, 'd');
        add(i, p.v, p.x, p.x+3, 'u');
    }
    

    int tt; cin >> tt;
    while(tt--) {
        stringstream ss;
        for(int i=0; i<9; i++) {
            string s; cin >> s;
            if (s=="x") s="0";
            ss << s;
        }

        string s = ss.str();
        if (M.find(s) == M.end()) {
            cout << "unsolvable" << endl;
        } else {
            Item item = Q[M[s]];
            
            while(item.p != -1) {
                cout << item.m; 
                item = Q[item.p];
            }
            cout << endl;
        }
        if (tt) cout << endl;
    }
}
