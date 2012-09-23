//1208
//Oreon
//Graphs;Minimum Spanning Tree;Prim
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#define MAX 501

using namespace std;

int G[MAX][MAX], n;
bool V[MAX];
int D[MAX], DO[MAX];

struct Item {
    int p, a, b;
    Item(){}
    Item(int p, int a, int b) : p(p), a(min(a,b)), b(max(a,b)) {}
};

bool comp(const Item& a, const Item& b) {
    if (a.p != b.p) return a.p < b.p;
    if (a.a != b.a) return a.a < b.a;
    if (a.b != b.b) return a.b < b.b;
    return false;
}

vector<Item> R;

int updateD(int i) {
    D[i] = 0;
    for(int j=0; j<n; j++) {
        if (G[i][j] && G[i][j] < D[j]) {
            D[j] = G[i][j];
            DO[j] = i;
        }
    }
}

int main() {
    int t; char skip;
    cin >> t;
    t = 0;
    while(cin >> n) {
        memset(V, 0, sizeof(V));
        memset(D, 0x3F, sizeof(D));
        R.clear();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> G[i][j];
                if (j+1<n) cin >> skip;
            }
        }

        int total = 0;

        V[0] = true;
        updateD(0);
        
        for(int k=1; k<n; k++) {
            int minn=INT_MAX, minv;
            for(int i=0; i<n; i++) {
                if (!V[i] && D[i] < minn) {
                    minn = D[i];
                    minv = i;
                }
            }
            R.push_back(Item(minn, DO[minv], minv));
            V[minv] = true;
            updateD(minv);
            total += minn;
        }
        
        sort(R.begin(), R.end(), comp);
        cout << "Case " << ++t << ":" << endl;
        for(int i=0; i<R.size(); i++) {
            cout << (char)(R[i].a+'A') << "-" << (char)(R[i].b+'A') << " " << R[i].p << endl;
        }
    }
    return 0;
}
