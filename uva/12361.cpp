//12361
//File Retrieval
//Misc;String Matching;Suffix Array;Longest Common Prefix
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <stack>
#define MAX 600200
#define ull unsigned long long
using namespace std;

struct Item {
    ull v; int p;
    Item(ull v, int p) : v(v), p(p) { }
};

int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int C[MAX];                
int Phi[MAX], PLCP[MAX], LCP[MAX];
int IDX[MAX], SIZ[MAX];
set<ull> R;

void suffix_sort(int n, int k) {
    memset(C, 0, sizeof C);        

    for (int i = 0; i < n; i++)        
        C[i + k < n ? RA[i + k] : 0]++;
        
    int sum = 0;
    for (int i = 0; i < max(256, n); i++) {                     
        int t = C[i]; 
        C[i] = sum; 
        sum += t;
    }

    for (int i = 0; i < n; i++)        
        tempSA[C[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

    memcpy(SA, tempSA, n*sizeof(int));
}

void suffix_array(string &s) {             
    int n = s.size();
    
    for (int i = 0; i < n; i++) 
        RA[i] = s[i] - 1;              

    for (int i = 0; i < n; i++) 
        SA[i] = i;


    for (int k = 1; k < n; k *= 2) {     
        suffix_sort(n, k);
        suffix_sort(n, 0);

        int r = tempRA[SA[0]] = 0;
        for (int i = 1; i < n; i++) {
            int s1 = SA[i], s2 = SA[i-1];
            bool equal = true;
            equal &= RA[s1] == RA[s2];
            equal &= s1+k < n && s2+k < n && RA[s1+k] == RA[s2+k];
            
            tempRA[SA[i]] = equal ? r : ++r;     
        }
                
        memcpy(RA, tempRA, n*sizeof(int));
    } 
}

void lcp(string &s) {
    int n = s.size();

    Phi[SA[0]] = -1;         
    for (int i = 1; i < n; i++)  
        Phi[SA[i]] = SA[i-1];  
    
    int L = 0;
    for (int i = 0; i < n; i++) {
        if (Phi[i] == -1) { 
            PLCP[i] = 0; 
            continue; 
        }
        while (s[i + L] != '\1' && s[i + L] == s[Phi[i] + L]) 
            L++;

        PLCP[i] = L;
        L = max(L-1, 0);                      
    }
    
    for (int i = 1; i < n; i++)                 
        LCP[i] = PLCP[SA[i]];
}

int main() {
    int n;
    while(cin >> n, n) {
        R.clear();
        
        stringstream ss; int kk = 0;
        for(int i=0; i<n; i++) {
            string temp; 
            cin >> temp;
            ss << temp << '\1';
            
            for(int j=0; j<=temp.size(); j++) {
                SIZ[kk] = temp.size()-j;
                IDX[kk] = i;
                kk++;
            }
        }

        string s = ss.str();

        suffix_array(s);
        lcp(s);
        
        stack<Item> ST;

        for(int i=n; i<s.size(); i++) {
            if (LCP[i] < SIZ[SA[i]] && (i+1==s.size() || LCP[i+1] < SIZ[SA[i]]))
                R.insert(1ull << IDX[SA[i]]);
        }

        for(int i=n; i<s.size(); i++) {
            ull lastv = 0;
            while(!ST.empty() && (ST.top().p > LCP[i] || LCP[i] == 0)) {
                Item item = ST.top(); ST.pop();

                R.insert(item.v);
                
                if (!ST.empty())
                    ST.top().v |= item.v;
                
                lastv = item.v;
            }
            if (LCP[i]) { 
                if (ST.empty() || ST.top().p < LCP[i]) {
                    ST.push(Item(1ull << IDX[SA[i]] | 1ull << IDX[SA[i-1]] | lastv, LCP[i]));
                } else if (ST.top().p == LCP[i]) {
                    ST.top().v |= 1ull << IDX[SA[i]];   
                } 
            }
        }
        
           
        while(!ST.empty()) {
            Item item = ST.top(); ST.pop();

            R.insert(item.v);
            if (!ST.empty())
                ST.top().v |= item.v;
        }
           
        
        cout << R.size() << endl;
   }
}
