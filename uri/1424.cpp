//1424
//Problema Fácil de Rujia Liu?
//Misc;Beginner
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

vector<int> T[1000010];

int main() {
    int n, m;
    while(cin >> n >> m) {
        memset(T, 0, sizeof T);
        for(int i=1; i<=n; i++) {
            int temp; cin >> temp;
            T[temp].push_back(i);
        }

        while(m--) {
            int k, v;
            cin >> k >> v;
            k--;
            if (k<T[v].size())
                cout << T[v][k] << endl;
            else
                cout << 0 << endl;
        }

    }
}
