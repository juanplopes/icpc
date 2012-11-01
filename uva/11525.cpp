//11525
//Permutation
//Misc;Fenwick Tree
#include <iostream>
#include <cstring>
#define MAX 50100
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
    
    int rsq(int b) {                   
        int sum = 0; 
        for (; b; b -= (b&-b)) 
            sum += T[b];
        return sum; 
    }

    int rsq(int a, int b) {            
        return rsq(b) - rsq(a - 1); 
    }
    
    int lower_bound(int x) {
        int first = 0, count = n;
        while (count>0)
        {
            int step=count/2; 
            int mid = first+step; 

            if (rsq(mid) < x) {
                first = mid+1;
                count -= step+1;  
            } else {
                count = step;
            }
        }
        return first;
    }
};

Fenwick T;

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        
        T.clear(n);
        for(int i=1; i<=n; i++)
            T.adjust(i, 1);

        
        for(int i=0; i<n; i++) {
            int k; cin >> k;

            int x = T.lower_bound(k+1);
            T.adjust(x, -1);

            if (i) cout << " ";
            cout << x;
        }
        cout << endl;
    }
    
    return 0;
}
