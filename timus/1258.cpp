//1258
//Pool
//Math;Geometry;Mirror
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#define ull long long

using namespace std;

int main() {
    ull W, D, a, b, c, d;
    string s;
    while(cin >> W >> D >> a >> b >> c >> d) {
        cin >> s;
        ull x=0, y=0;
        ull sr=1<<30, sl=1<<30, sf=1<<30, sb=1<<30;

        for(ull i=0; i<s.size(); i++) {
            switch(s[i]) {
                case 'R': x+=2*(W-c); sr = min(sr, i); break;
                case 'L': x+=2*c; sl = min(sl, i); break;
                case 'F': y+=2*d; sf = min(sf, i); break;
                case 'B': y+=2*(D-d); sb = min(sb, i); break;
            }
        }
        
        c += sr<sl?x:-x;
        d += sb<sf?y:-y;

        cout << fixed << setprecision(4) << sqrt((a-c)*(a-c)+(b-d)*(b-d)+0.0) << endl;

    }
}
