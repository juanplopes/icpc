//1232
//SKYLINE
//Misc;Segment Tree
#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Node {
    int a, b, h;
    bool leaf;
    Node() {}
    Node(int a, int b, int h, bool leaf=true) : a(a), b(b), h(h), leaf(leaf) {}
};

Node H[5000005];
inline int left(int i) { return 2*i; }
inline int right(int i) { return 2*i+1; }

inline void cut(int v, int x) {
    H[left(v)] = Node(H[v].a, x, H[v].h);
    H[right(v)] = Node(x, H[v].b, H[v].h);
    H[v].leaf = false;
}

int dfs(int v, int a, int b, int h) {
    a = max(a, H[v].a); 
    b = min(b, H[v].b);
    if (b<=a) return 0;
    
    if (!H[v].leaf) 
        return dfs(left(v), a, b, h) + dfs(right(v), a, b, h);
    
    if (H[v].h > h) return 0;
    if (H[v].a < a) return cut(v, a), dfs(v, a, b, h);
    if (b < H[v].b) return cut(v, b), dfs(v, a, b, h);
        
    H[v].h = h;
    return b-a;
}

int main() {
    int n, t; cin >> t; t=0;
    while(cin >> n, n) {
        H[1] = Node(0, 100000, 0);

        int sum = 0;
        while(n--) {
            int a, b, h;
            cin >> a >> b >> h;
            sum += dfs(1, a, b, h);
        }
        cout << sum << endl;
        
    }
}
