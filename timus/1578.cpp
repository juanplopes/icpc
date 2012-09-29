//1578
//Mammoth Hunt
//Math;Geometry;Segments Angle
#include <iostream>
#include <cmath>         
#define EP 1e-6
#define PI 3.14159265
using namespace std;

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    double dist(Point A) {
        return sqrt(pow(A.x-x,2.0)+pow(A.y-y,2.0));
    }

    double angle(Point B, Point C) {
        double a = dist(B), b = B.dist(C), c=dist(C);  
        double ret = acos((a*a+b*b-c*c) / (2*a*b));
        if (ret < 0) ret += 2*PI;
        //cout << " " << a << " " << b << " " << c << " " << ret << endl; 
        return ret;
    }
    
    bool accute(Point B, Point C) {
        return angle(B, C) < PI/2.0;
    }

};

Point P[2010];
int O[2010], V[2010];
int n;

bool dfs(int v, int i) {
    O[i] = v; V[v] = i;
    if (i==n) return true;
    
    for(int j=1; j<=n; j++) {
        if (V[j]) continue;
        Point a = P[O[i-1]], b = P[O[i]], c = P[j];
        if (a.accute(b,c))
            if (dfs(j, i+1))           
                return true;
    }
    V[v] = 0;
    
    return false;
    
}

int main() {
    int k;
    while(cin >> k) {
        memset(O, 0, sizeof(O));
        memset(V, 0, sizeof(V));
        
        n = k + 2;
        for(int i=1; i<=n; i++) 
            cin >> P[i].x >> P[i].y;

        bool ok = false;
        for(int i=1; i<=n && !ok; i++) {
            O[1] = i; V[i] = 1;
            for(int j=1; j<=n && !ok; j++) {
                if (i==j) continue;
                ok |= dfs(j, 2);
            }   
        }
        
        if (ok) {
            cout << "YES" << endl;
            for(int i=1; i<=n; i++) {
                if (i>1) cout << " ";
                cout << O[i];
            }   
            cout << endl;
        } else {
            cout << "NO" << endl;   
        }

        
    }
}
