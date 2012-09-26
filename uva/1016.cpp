//1016
//Silly Sort
//Misc;Permutation Cycle
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 2000
using namespace std;

int T[MAX], Q[MAX], M[MAX];
bool V[MAX];

int main() {
    int n, t=0;
    while(cin >> n, n) {
        memset(V, 0, sizeof(V));

        int minn=1<<30;
        for(int i=0; i<n; i++) {
            cin >> T[i];
            minn = min(minn, T[i]);
        }
        
        memcpy(Q, T, sizeof(T));
        sort(Q, Q+n);
        for(int i=0; i<n; i++) {
            M[Q[i]] = i;
        }
        
        int answer = 0;
        for(int i=0; i<n; i++) {
            if (V[i]) continue;
            
            int cycle = 0, minc=1<<30, sumc=0;
            for(int j=i; !V[j]; j=M[T[j]]) {
                V[j] = true;   
                sumc += T[j];
                minc = min(minc, T[j]);
                cycle++;
            }            
            
            answer += min(sumc + (cycle-2)*minc, sumc + minc + minn * (cycle+1));
        }
        
        cout << "Case " << ++t << ": " << answer << endl << endl;
    }
}
