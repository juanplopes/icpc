//12086
//Potentiometers
//Misc;Fenwick Tree
#include <iostream>
#include <cstring>
#include <string>
#define MAX 200100
using namespace std;

struct Fenwick {
    int T[MAX];
    int n;

    Fenwick() {
        clear(0);
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
    
    void update(int k, int v) {
        adjust(k, v-rsq(k, k));
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

int main() {
    int n, tt=0; 
    while(cin >> n, n) {
        if (tt++) cout << endl;
        cout << "Case " << tt << ":" << endl;
        
        T.clear(n);
        for(int i=1; i<=n; i++) {
            int a; cin >> a;
            T.adjust(i, a);
        }
        
        string cmd;
        while(cin >> cmd, cmd!="END") {
            int a, b; cin >> a >> b;
            if (cmd == "S") {
                T.update(a, b);
            } else {
                cout << T.rsq(a, b) << endl;
            }
        }
    }
}
