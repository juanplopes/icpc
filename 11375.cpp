//11375
//Matches
//Dynamic Programming;Ad hoc
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int K[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> T[2001][10];

void add(vector<int> &a, const vector<int> &b) {
    int carry = 0;
    for(int i=0;i<max(a.size(), b.size());i++) {
        int aa = i<a.size()?a[i]:0;
        int bb = i<b.size()?b[i]:0;
        int cc = aa+bb+carry;
        if (i >= a.size()) a.push_back(0);
        a[i] = cc%10;
        carry = cc/10;
    }
    if (carry)
        a.push_back(carry);
}

int main() {
    vector<int> one; one.push_back(1);
    
    for(int i=2; i<2001; i++) {
        for(int j=0;j<10; j++)
            if (i>=K[j]) {
                add(T[i][j], one);
                for(int k=0;k<10;k++)
                    add(T[i][j], T[i-K[j]][k]);
            }
    }

    int n;
    while(cin >> n) {
        vector<int> ans = n>=6?one:vector<int>();
        for(int i=1;i<10;i++)
            add(ans, T[n][i]);
            
        for(int i=ans.size()-1;i>=0;i--) {
            cout << ans[i];
        }
        if (ans.size()==0) cout << 0;
        cout << endl;
    }
    
    return 0;
}
