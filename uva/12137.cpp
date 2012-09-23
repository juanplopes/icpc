//12137
//Puzzles of Triangles
//Math;Prime Factorization
#include <string.h>
#include <stdio.h>
#define ull unsigned long long

int W[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }, wn = 23;

inline ull div(const ull& a, const ull& b, ull &r) {
    r = a/b;
    return a-r*b;
}

inline ull pow(const ull& a, const int b) {
    if (b==0) return 1;
    ull tmp = b&1 ? a : 1;
    ull r = pow(a, b>>1);
    return tmp*r*r;
}

int main() {
    ull n;
    int t=0;
    while(scanf("%llu", &n), n) {
        ull ncopy = n;
        ull step = 1;
        for(int i=0; ncopy>1 && i<wn; i++) {
            int power=0;
            ull divr;
            while(div(ncopy, W[i], divr)==0) {
                ncopy = divr;
                power++;
            }
            step *= pow(W[i], (power+1)/2);
        }
        step *= ncopy;
        
        ull result;
        if (div(n, step, result)==0) result--;
        result *= 8;
        
        if(result)
            printf("Case %d: %llu\n",++t, result);
        else
            printf("Case %d: Impossible\n", ++t);
    }
}
