//136
//Ugly Numbers
//Misc;Ad hoc
#include <iostream>
#include <queue>
#define ull unsigned long long
using namespace std;

struct Number {
    ull n, p;
    Number(ull n, ull p) : n(n), p(p) {}
    inline const bool operator < (const Number& that) const {
        return n > that.n;
    }
};

priority_queue<Number> Q; 
int main() {
    Q.push(Number(1,1));
    for(int i=1; i<1500; i++) {
        Number last = Q.top(); Q.pop();
        if (last.p <= 2) Q.push(Number(last.n*2, 2));
        if (last.p <= 3) Q.push(Number(last.n*3, 3));
        if (last.p <= 5) Q.push(Number(last.n*5, 5));
    }

    cout << "The 1500'th ugly number is " << Q.top().n << "." << endl;
    
    return 0;
}
