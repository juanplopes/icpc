//760
//DNA Sequencing
//Misc;String Matching;Suffix Array;Longest Common Prefix
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 10050
using namespace std;

int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int C[MAX];                
int Phi[MAX], PLCP[MAX], LCP[MAX];

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
            equal &= RA[s1+k] == RA[s2+k];
            
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
        while (s[i + L] == s[Phi[i] + L]) 
            L++;

        PLCP[i] = L;
        L = max(L-1, 0);                      
    }
    
    for (int i = 1; i < n; i++)                 
        LCP[i] = PLCP[SA[i]];
}

int main() {
    string a, b, s;
    int tt = 0;
    while(getline(cin, a) && getline(cin, b)) {
        if (tt++) cout << endl;
        getline(cin, s);
        s = a+"\1"+b+"\2";
        suffix_array(s);
        lcp(s);

        int maxx = 0;
        for(int i=1; i<s.size(); i++) {
            bool left = SA[i-1]+LCP[i] <= a.size();
            bool right = SA[i]+LCP[i] <= a.size();

            if (LCP[i] && (left^right)) {
                maxx = max(maxx, LCP[i]);
            }
        }
        
        if (maxx == 0) {
            cout << "No common sequence." << endl;
            continue;
        }
        
        string last = "some invalid string";
        for(int i=1; i<s.size(); i++) {
            bool left = SA[i-1]+LCP[i] <= a.size();
            bool right = SA[i]+LCP[i] <= a.size();
            string sub = s.substr(SA[i], maxx);

            if (LCP[i]==maxx && (left^right) && last != sub) {
                cout << sub << endl;
                last = sub;
            }
        }
   }
}
