//10113
//Exchange Rates
//Graphs;DFS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b) {
    while(b) 
        swap(a=a%b,b);
    return a;
}

struct Edge {
    string s;
    int a, b;
    Edge() : a(0), b(0) { }
    Edge(string s, int a, int b) : s(s), a(a), b(b) {}
    
    Edge next(Edge e) {
        int na = a*e.a, nb = b*e.b;
        int g = gcd(na, nb);
        na /= g; nb /= g;
        return Edge(e.s, na, nb);
    }
    
    bool valid() { return a!=0; }
};


map<string, vector<Edge> > G;
set<string> V;

Edge dfs(Edge e, string target) {
    if (e.s == target) return e;
    V.insert(e.s);
    vector<Edge> ve = G[e.s];

    for(int i=0; i<ve.size(); i++) {
        if (V.find(ve[i].s) == V.end()) {
            Edge other = dfs(e.next(ve[i]), target);
            if (other.valid()) return other;
        }
    }

    return Edge();
}

int main() {
    string cmd;

    while(cin >> cmd, cmd!=".") {
        string s1, s2, temp;
        if (cmd == "!") {
            int x, y; 
            cin >> x >> s1 >> temp >> y >> s2;
            G[s1].push_back(Edge(s2, x, y));
            G[s2].push_back(Edge(s1, y, x));
        } else if (cmd == "?") {
            cin >> s1 >> temp >> s2;
            V.clear();
            Edge e = dfs(Edge(s1, 1, 1), s2);
            if (e.valid())
                cout << e.a << " " << s1 << " = " << e.b << " " << s2 << endl;                   
            else
                cout << "? " << s1 << " = ? " << s2 << endl;                   
        }
        
    }
}
