//11423
//Cache Simulator
//Misc;Fenwick Tree
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10000100
using namespace std;

struct Fenwick {
    int T[MAX];
    int n;

    Fenwick() {
        clear(MAX);
    }
    
    void clear(int n) {
        n++;
        memset(T, 0, n*sizeof(int));
        this->n = n;               
    }
    
    void adjust(int k, int v) {
        for (; k < n; k += (k&-k)) 
            T[k] += v; 
    }
    
    int rsq(int b) {                   
        int sum = 0; 
        for (; b; b -= (b&-b)) 
            sum += T[b];
        return sum; 
    }

    int rsq(int a, int b) {            
        return rsq(b) - rsq(a - 1); 
    }
};

Fenwick T;
int C[40], S[40], P[1<<24];
int caches=0, query=0;

void access(int addr) {
    if (P[addr]) {
        int maxCache = T.rsq(P[addr], query);

        int upto = lower_bound(C, C+caches, maxCache)-C;

        for(int i=0; i<upto; i++)
            S[i]++;

        T.adjust(P[addr], -1);
    } else {
        for(int i=0; i<caches; i++)
            S[i]++;                
    }
 
    T.adjust(P[addr] = ++query, 1);
}

int main() {
    cin >> caches;
    for(int i=0; i<caches; i++)
        cin >> C[i];
    
    string cmd;
    while(cin >> cmd, cmd != "END") {
        if (cmd == "ADDR") {
            int x; 
            cin >> x;
            access(x);
        }  else if (cmd == "RANGE") {
            int b, y, n; 
            cin >> b >> y >> n;
            
            for(int i=0; i<n; i++)
                access(b+i*y);
        } else {
            for(int i=0; i<caches; i++) {
                if (i) cout << " ";
                cout << S[i];
            }
            cout << endl;
            memset(S, 0, sizeof S);
        }
    }
    
    
    
    return 0;
}
