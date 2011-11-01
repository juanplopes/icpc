//1215
//String Cutting
//Misc;Binary Search
#include <iostream>
#include <string>
#include <set>
using namespace std;

int T[10001][26];
int C[1001];
set<int> K;

int main() {
    int t; cin >> t; t=0;
    int k; string s;
    while(cin >> k) {
        K.clear();
        for(int i=0; i<k; i++)
            cin >> C[i];

        cin >> s;
        for(int i=1; i<=s.size(); i++)
            for(int j=0; j<26; j++)
                T[i][j] = T[i-1][j] + (s[i-1] == j+'a');
            

        K.insert(0);
        K.insert(s.size());
        
        int total = 0;
        for(int i=0; i<k; i++) {
            int mid = C[i];
            set<int>::iterator it = K.lower_bound(mid);
            int hi = *it; it--;
            int lo = *it;
            
            for(int j=0; j<26; j++) {
                int sidea = T[mid][j]-T[lo][j];
                int sideb = T[hi][j]-T[mid][j];

                if (sidea>0 ^ sideb>0) total++;
            }
            K.insert(mid);
        }
        cout << total << endl;
    }
}
