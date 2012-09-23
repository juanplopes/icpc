//1216
//The Bug Sensor Problem
//Graphs;DFS
#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 1000
using namespace std;

double G[MAX][MAX];
int X[MAX], Y[MAX], n, k;
int V[MAX];

void dfs(int v, int comp, int max) {
    V[v] = comp;
    for(int i=0; i<n; i++) {
        if (!V[i] && G[v][i] <= max)
            dfs(i, comp, max);
    }
}

int main() {
    int t; cin >> t; t=0;
    while(cin >> k) {
        n=0;
        
        double maxd=0;
        while(cin >> X[n], X[n]!=-1) {
            cin >> Y[n];
            for(int i=0; i<n; i++) {
                G[i][n] = G[n][i] = sqrt(pow(X[n]-X[i], 2.0)+pow(Y[n]-Y[i], 2.0));
                maxd = max(maxd, G[i][n]);
            }
            n++;
        }
        
        int begin=0, end=(int)ceil(maxd);
        int best, last = -1;
        while(begin <= end) {
            int mid = (begin+end)/2;
            if (mid == last) break;
            
            int comp=0;
            memset(V, 0, sizeof(V));
            for(int i=0; i<n; i++)
                if (!V[i])
                    dfs(i, ++comp, mid);

            last = mid;
            if (comp > k)
                begin = mid;
            else {
                if (comp == k) best = mid;
                end = mid;
            }
        }
        
        cout << best << endl;
    }
}
