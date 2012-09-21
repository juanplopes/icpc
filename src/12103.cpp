//12103
//Leonardo's Notebook
//Misc;Permutation Cycle
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;

        int notzero = 0, visited = 0;
        for(int i=0; i<s.size(); i++) {
            if (visited & 1<<i) continue;

            int cycle = 0;
            for(int j=i; ~visited & 1<<j; j=s[j]-'A') {
                visited |= 1<<j;
                cycle++;
            }
            if (cycle % 2 == 0)
                notzero ^= 1<<cycle;
        }        
        
        cout << (notzero ? "No" : "Yes") << endl;
    }    
}
