//12101
//Prime Path
//Graphs;Shortest Path;BFS
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

bool P[10000], V[10000];

struct Step {
    int a, b, c, d, w;
    Step() {}
    Step(int a, int b, int c, int d, int w) : a(a), b(b), c(c), d(d), w(w) {}
    
    int number() { return a*1000+b*100+c*10+d; }
    bool valid() { return a && P[number()]; }
    
    Step atA(int n) { return Step(n, b, c, d, w+1); }
    Step atB(int n) { return Step(a, n, c, d, w+1); }
    Step atC(int n) { return Step(a, b, n, d, w+1); }
    Step atD(int n) { return Step(a, b, c, n, w+1); }
};

Step makestep(int n) {
    int a, b, c, d;
    d = n%10; n/=10;
    c = n%10; n/=10;
    b = n%10; n/=10;
    a = n%10; n/=10;
    return Step(a,b,c,d,0);
}

int main() {
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for(int i=2; i<10000; i++) {
        if (P[i]) {
            for(int j=i*i; j<10000; j+=i)
                P[j] = false;
        }
    }
    int t, a, b;
    cin >> t;
    while(cin >> a >> b) {
        memset(V, 0, sizeof(V));
        queue<Step> Q;
        Q.push(makestep(a));
        bool found = false;
        while(!Q.empty()) {
            Step step = Q.front(); Q.pop();
            int n = step.number();
            if (V[n]) continue;
            V[n] = true;
            if (n == b) {
                cout << step.w << endl;
                found = true;
                break;
            }
            for(int i=0;i<=9;i++) {
                Step sa = step.atA(i);
                Step sb = step.atB(i);
                Step sc = step.atC(i);
                Step sd = step.atD(i);
                if (sa.valid()) Q.push(sa);
                if (sb.valid()) Q.push(sb);
                if (sc.valid()) Q.push(sc);
                if (sd.valid()) Q.push(sd);
            }
        }
        if (!found) cout << "Impossible" << endl;
    }
    
}
