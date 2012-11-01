//11610
//Reverse Prime
//Misc;Fenwick Tree
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000100
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
    
    int value(int b) {
        return rsq(b, b);
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

Fenwick T, Q;
int P[MAX], W[MAX], wn=0, I[MAX], in=0, F[MAX];

int invert(int n) {
    int r=0;
    while(n) {
        r *= 10;
        r += n%10;
        n/=10;
    }
    return r;
}

int factors(int n, int start) {
    if (F[n]) return F[n];
    if (not P[n]) return F[n] = 1;

    for(;;start++)
        if (n%W[start] == 0)
            return factors(n/W[start], start)+1;
}


int main() {
    P[1] = true;
    for(long long i=2; i<MAX; i++) {
        if (P[i]) continue;
        W[wn++] = i;
        for(long long j=i*i; j<MAX; j+=i)
            P[j] = true;
    }

   
    for(int i=100000; i<1000000; i++) {
        if (not P[invert(i)]) {
            I[i]=++in;  
            Q.adjust(in, 1); 
            T.adjust(in, factors(i, 0)+2);
        }
    }
   
    char c; int n;
    while(cin >> c >> n) {
        if (c=='q') {
            cout << T.rsq(Q.lower_bound(n+1)) << endl;
        } else {
            n/=10;
            T.adjust(I[n], -T.value(I[n]));
            Q.adjust(I[n], -1);
        }
    }
    
    
    return 0;
}
