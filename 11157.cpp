//11157
//Dynamic Frog
//Misc;Sort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;

int main() {
    int t, n, d;
    cin >> t; t=0;
    
    while(cin >> n >> d) {
        char a; int b;
        V.clear();
        V.push_back(0);
        V.push_back(d);
        for(int i=0;i<n; i++) {
            cin >> a; cin.ignore(); cin >> b;
            V.push_back(b);
            if (a=='B')
                V.push_back(b);
        }        
        sort(V.begin(), V.end());
        
        int maxx = 0;
        for(int i=3;i<V.size(); i+=2)
            maxx = max(maxx, V[i]-V[i-2]);

        for(int i=2;i<V.size(); i+=2)
            maxx = max(maxx, V[i]-V[i-2]);
        
        cout << "Case " << ++t << ": " << maxx << endl;
    }
    
}
