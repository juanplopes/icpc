//811
//The Fortified Forest
//Math;Geometry;Convex Hull;Monotone Chain
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define EP 1e-6
using namespace std;

struct Tree {
    int x, y, v, l;

    int product(Tree a, Tree b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    bool left(Tree a, Tree b) {
        return product(a, b) < 0;
    }

    double dist(Tree b) {
        return sqrt(pow(x-b.x, 2.0) + pow(y-b.y, 2.0));   
    }

    bool operator <(const Tree& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Tree& p) const {
        return this->x == p.x and this->y == p.y;
    }
};

int convexHull(Tree* P, int n, Tree* S) {
    sort(P, P+n);

    int m=0;
    for(int i=0; i<n; i++) {
        while(m >= 2 && S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    for(int i=n-1, k=m; i >= 0; i--) {
        while(m >= k+2 && S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;
    
    return m;
}


Tree P[20], T[20], S[20];

int main() {
    int n, tt=0;
    while(cin >> n, n) {
        for(int i=0; i<n; i++) {
            cin >> P[i].x >> P[i].y >> P[i].v >> P[i].l;         
        }
        int mini = 0, minv = 1<<30, minc = 1<<30;
        double mine = 0.0;

        for(int i=0; i<(1<<n); i++) {
            int value = 0, length = 0, count=0, ts=0;
            for(int j=0; j<n; j++) {
                if (i & 1<<j) {
                    value += P[j].v;
                    length += P[j].l;  
                    count++;
                } else {
                    T[ts++] = P[j];   
                }
            }   
            if (value > minv) continue;
            int s = convexHull(T, ts, S);
            
            double perimeter = 0;
            for(int j=0; j<s; j++)
                perimeter += S[j].dist(S[(j+1)%n]);

            if (length > perimeter-EP && (value < minv || value == minv && count < minc)) {
                mini = i;
                minc = count;
                minv = value;
                mine = length - perimeter;    
            }
        }
        
        if (tt) cout << endl;
        cout << "Forest " << ++tt << endl;
        cout << "Cut these trees:";
        for(int i=0; i<n; i++)
            if (mini & 1<<i)
                cout << " " << i+1;   
        cout << endl;
        cout << "Extra wood: " << fixed << setprecision(2) << mine << endl;
        
    }   
}
