//1373
//Pictura ex Machina
//Math;Geometry;3D Line Detection
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int gcd(int a, int b) {
    while(b)
        swap(a=a%b,b);
    return a;
}   

struct Vector {
    int x, y, z;
    
    Vector() : x(0), y(0), z(0) {}
    Vector(int x, int y, int z) : x(x), y(y), z(z) {}
    
      
    Vector normalize() const {
        int d = gcd(x, gcd(y, z));
        return Vector(x/d, y/d, z/d);
    }
    
    Vector operator -(const Vector& that) const {
        return Vector(x-that.x, y-that.y, z-that.z);
    }
    
    bool operator <(const Vector& that) const {
       if (x!=that.x) return x<that.x;
       if (y!=that.y) return y<that.y;
       return z<that.z;
    }
    
};


Vector P[2007];
map<Vector, int> M;

int main() {
    int n;
    while(cin >> n) {
        for(int i=0; i<n; i++)
            cin >> P[i].x >> P[i].y >> P[i].z;      
    
        int maxx = 0;
        for(int i=0; i<n; i++) {
            M.clear();
            for(int j=i+1; j<n; j++)
                maxx = max(maxx, ++M[(P[i]-P[j]).normalize()]);
        }
        
        cout << maxx+1 << endl;

    }
}
