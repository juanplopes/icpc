//12186
//Another Crisis
//Graphs;DFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 100002
using namespace std;

vector<int> G[MAX];
int n, t;

int dfs(int v) {
    if (G[v].empty()) return 1;
    vector<int> mins;
    for(int i=0; i<G[v].size(); i++)
        mins.push_back(dfs(G[v][i]));
    sort(mins.begin(), mins.end());
    
    int get = (int)ceil(G[v].size()*t/100.0);
    int sum = 0;
    for(int i=0; i<get; i++) sum+=mins[i];
    return sum;
}

int main() {
    int boss;
    while(cin >> n >> t, n|t) {
        memset(G, 0, sizeof(G));
        for(int i=1; i<=n; i++) {
            cin >> boss; G[boss].push_back(i);
        }
        cout << dfs(0) << endl;
    }
    return 0;
}
