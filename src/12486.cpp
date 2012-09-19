//12486
//Space Elevator
//Misc;Binary Search
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#define ull unsigned long long int
using namespace std;

ull T[20][10];

bool has(ull n, ull k, ull p) {
    while(n) {
            if (n%p==k) return true;
            n/=10;
    }
    return false;
}

bool has(ull n) {
    return has(n, 13, 100) || has(n, 4, 10);
}

ull right(ull n) {
    int log10 = 0;
    ull right = 0;
        
    if (!has(n))
        right++;
    
    while(n) {
        ull hi = n/10;
        ull lo = n%10;

        if (!has(hi)) {
            for(ull i=0; i<lo; i++) {
                if (i!=4 && (hi%10 != 1 || i!=3))
                    right += T[log10][i];
            }
        }

        log10++;
        n/=10;
    }

    return right-1;
}

ull answer(ull n) {
    ull begin=0, end=-1;

    while(begin+1 < end) {
        ull mid = begin + (end - begin)/2;
        ull v = right(mid);

        if (v>=n)
            end = mid;
        else
            begin = mid;
    }
  
    if (right(begin) == n)
        return begin;
    else
        return end;
}

int main() {
    for(ull i=0; i<10; i++) {
        if (i==4) continue;
        T[0][i] = 1;
    }

    for(ull i=1; i<20; i++) {
        for(ull j=0; j<10; j++) {
            if (j==4) continue;
            for(ull k=0; k<10; k++) {
                if (k==3 and j==1) continue;
                T[i][j] += T[i-1][k];
            }
        }
    }


    ull n;
    while(cin >> n) {
       cout << answer(n) << endl;
    }
}
