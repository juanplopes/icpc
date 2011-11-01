//10154
//Weights and Measures
//Dynamic Programming;Longest Increasing Subsequence
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#define MAX 10005
using namespace std;

struct Turtle {
    int w,c;
    Turtle() {}
    Turtle(int w, int c) : w(w), c(c) {}
};

bool compare(const Turtle& a, const Turtle& b) {
    return a.c > b.c;
}

vector<Turtle> V;
int T[MAX];
int main() {
    int w, c, k=0;
    T[0] = INT_MAX;

    while(cin >> w >> c) {
        V.push_back(Turtle(w, c-w));
    }
    sort(V.begin(), V.end(), compare);
    
    for(int i=0; i<V.size(); i++) {
        int w = V[i].w, c = V[i].c;
        
        for(int j=k; j>=0; j--) {
            int next = min(T[j]-w, c);
            if (next >= T[j+1]) {
                T[j+1] = next;
                k=max(k, j+1);
            }
        }
    }
    cout << k << endl;

    return 0;
}
