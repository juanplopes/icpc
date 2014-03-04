//1520
//Screws and Nuts
//Misc;Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

int T[100000];

int main() {
    int n, k;
    while(cin >> n) {
        int tt = 0;
        for(int i=0; i<n; i++) {
            int a, b; cin >> a >> b;
            for(int j=a; j<=b; j++) {
                T[tt++] = j;
            }
        }
        
        sort(T, T+tt);

        cin >> k;
        int begin = lower_bound(T, T+tt, k)-T;
        int end = upper_bound(T, T+tt, k)-T;
        if (begin < end) {
            cout << k << " found from " << begin << " to " << end-1 << endl;        
        } else {
            cout << k << " not found" << endl;
        }

    }
}

