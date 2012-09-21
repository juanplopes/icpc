//12490
//Integral
//Misc;Ad hoc
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 1000006
#define ull long long
using namespace std;

struct Value {
    int x;
    ull v;

    inline bool operator <(const Value& a) const {
        return this->x < a.x;
    }
};

Value F[MAX];

int main() {
    int n, s, y;            
    while(cin >> n >> s >> y) {
        for(int i=0; i<s; i++) {
            cin >> F[i].x >> F[i].v;
        }
            
        sort(F, F+s);

        double minn = 0, maxx = 0;

        for(int i=0; i<s-1; i++) {
            Value a = F[i], b = F[i+1];
            
            minn += min(a.v, b.v) + (b.x - a.x-1) * min(a.v, b.v) + abs(a.v - b.v)/2.0;
            maxx += min(a.v, b.v) + (b.x - a.x-1) * max(a.v, b.v) + abs(a.v - b.v)/2.0;
        }

        if (y < minn || y > maxx || ceil(minn) != minn) {
            cout << "N" << endl; continue;
        }
        
        cout << "S";
        
        ull current = round(maxx);
        for(int i=0; i<s-1; i++) {
            Value a = F[i], b = F[i+1];
            
            ull delta = (b.x - a.x-1) * (max(a.v, b.v) - min(a.v, b.v));
            
            if (current == y) {
                for(int x = a.x+1; x<b.x; x++)
                    cout << " " << max(a.v, b.v);
            } else if (current - delta > y) {
                current -= delta;
                
                for(int x = a.x+1; x<b.x; x++)
                    cout << " " << min(a.v, b.v);
            } else if (a.v < b.v) {
                for(int x=a.x+1; x<b.x; x++) {
                    ull value = max(a.v, b.v - (current - y));
                    cout << " " << value;
                    current -= b.v - value;
                }
            } else {
                ull plus = (current - y) / (b.x - a.x - 1);
                ull rem = (current - y) % (b.x - a.x - 1);
                for(int x=a.x+1; x<b.x; x++) {
                    ull value = a.v - plus - (b.x - x <= rem ? 1: 0);
                    cout << " " << value;
                    current -= a.v - value;
                }
            }
        }
        cout << endl;
        
    }
}
