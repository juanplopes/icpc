//12365
//Jupiter Atacks!
//Misc;Fenwick Tree
#include <iostream>
#include <cstring>
#define MAX 100100
#define ull long long
using namespace std;

struct Fenwick {
    ull T[MAX];
    int n;

    Fenwick() {
        clear(0);
    }
    
    void clear(int n) {
        n++;
        memset(T, 0, n*sizeof(ull));
        this->n = n;               
    }
    
    void adjust(int k, ull v, ull p) {
        for (; k < n; k += (k&-k)) {
            T[k] += v; 
            T[k] %= p;
        }
    }
    
    void update(int k, ull v, ull p) {
        ull current = rsq(k, k, p);
        adjust(k, v-current, p);
    }
    
    ull rsq(int b, ull p) {                   
        ull sum = 0; 
        for (; b; b -= (b&-b))
            sum += T[b]%p;
        return sum; 
    }

    ull rsq(int a, int b, ull p) {            
        return (rsq(b, p) - rsq(a - 1, p) + p) % p;
    } 
};

ull pow(ull a, ull b, ull p) {
    if (not b) return 1;
    ull x = pow(a%p, b%p/2, p) % p;
    x = (x*x)%p;
    if (b%2) x = (x*a)%p;
    return x;
}

ull euclid(ull a, ull b, ull& rx, ull& ry) {
    if (!b) return rx=1, ry=0, a;
    
    ull q = a/b;
    ull x, y;
    ull g = euclid(b, a-q*b, x, y);
    return rx=y, ry=x-q*y, g;
}

ull invert(ull a, ull p) {
    ull inverse, temp;
    euclid(a, p, inverse, temp);
    return inverse;
}

Fenwick T;

int main() {
    int B, P, L, N;
    while(cin >> B >> P >> L >> N, B|P|L|N) {
        T.clear(L);
        for(int i=0; i<N; i++) {
            char cmd; ull a, b;
            cin >> cmd >> a >> b;
            if (cmd == 'E') {
                T.update(a, b*pow(B, L-a, P), P);
            } else {
                ull raw = T.rsq(a, b, P);
                ull base = pow(B, L-b, P);
                
                cout << ((raw*invert(base, P))%P+P)%P << endl;
            }
        } 
        cout << "-" << endl;
    }
    
    return 0;
}
