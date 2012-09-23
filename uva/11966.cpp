//11966
//Galactic Bonding
//Misc;Union-Find
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int P[1000];
double X[1000], Y[1000];

inline int findset(int v) {
    if (P[v] == v) return v;
    return P[v] = findset(P[v]);
}

inline bool unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return false;
    P[b] = a;
    return true;
}

inline double dist(int a, int b) {
    return pow(X[a]-X[b], 2.0)+pow(Y[a]-Y[b], 2.0);
}

int main() {
    int t; cin >> t; t=0;
    
    int n; double d;
    while(cin >> n >> d) { 
        for(int i=0; i<n; i++) P[i] = i;
        
        int sets = n;
        for(int i=0; i<n; i++) {
            cin >> X[i] >> Y[i];
            for(int j=0;j<i;j++)
                if (dist(i,j)<=d*d && unionset(i, j))
                    sets--;
        }
        
        cout << "Case " << ++t << ": " << sets << endl;
    }
}
