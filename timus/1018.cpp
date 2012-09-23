//1018
//Binary Apple Tree
//Dynamic Programming;Ad hoc
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 105
using namespace std;

struct Node {
    int x, v;
    Node(int x, int v) : x(x), v(v) {}   
};
vector<Node> T[MAX];
int S[MAX], TT[MAX][MAX];
bool V[MAX][MAX];

void adjust(int root, int parent) {
    for(int i=0; i<T[root].size(); i++) {
        Node node = T[root][i];
        if (node.x != parent) {
            adjust(node.x, root);
            S[node.x] = node.v;
        } else {
            T[root].erase(T[root].begin()+i);
            i--;
        }
    }
}

int answer(int root, int branches) {
    if (V[root][branches]) 
        return TT[root][branches];

    if (branches == 0) return 0;
    if (branches == 1) return S[root];
    if (T[root].size() == 0) return S[root];
    if (T[root].size() == 1) return S[root] + answer(T[root][0].x, branches-1);

    Node left = T[root][0];
    Node right = T[root][1];
    
    int maxx = 0;
    for(int i=0; i<=branches-1; i++)
        maxx = max(maxx, S[root] + answer(left.x, i) + answer(right.x, branches-1-i));
          
    V[root][branches] = true;
    return TT[root][branches] = maxx;
}

int main() {
    int n, q;   
    while(cin >> n >> q) {
        memset(T, 0, sizeof(vector<int>)*n);
        memset(V, 0, sizeof(vector<int>)*n);
        memset(S, 0, sizeof(S));

        for(int i=0; i<n-1; i++) {
            int a, b, c; cin >> a >> b >> c;
            T[b].push_back(Node(a,c));
            T[a].push_back(Node(b,c));
        }
        adjust(1, -1);
        cout << answer(1, q+1) << endl;
    }
}
