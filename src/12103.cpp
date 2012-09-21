//12103
//Leonardo's Notebook
//Misc;Permutation Cycle
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool V[30];

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        memset(V, 0, sizeof(V));

        int notzero=0;
        for(int i=0; i<s.size(); i++) {
            if (V[i]) continue;

            int cycle = 0;
            for(int j=i; !V[j]; j=s[j]-'A') {
                V[j] = true;
                cycle++;
            }
            if (cycle % 2 == 0)
                notzero ^= 1<<cycle;
        }        
        
        cout << (notzero ? "No" : "Yes") << endl;
    }    
}
