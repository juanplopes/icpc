//361
//Cops and Robbers
//Math;Geometry;Convex Hull;Monotone Chain
#include <iostream>
#include <map>
#include <string>
using namespace std;

set<string> S;

int main() {
    int c, r, o, tt=1;
    while(cin >> c >> r >> o, c|r|o) {
        for(int i=0; i<c; i++)
            cin >> C[i].x >> C[i].y;        

        for(int i=0; i<r; i++)
            cin >> R[i].x >> R[i].y;        
            
        int cs = convexHull(C, c, CS);
        int rs = convexHull(R, r, RS);
        
        /*for(int i=0; i<cs; i++) {
            cout << " " << CS[i].x << " " << CS[i].y << endl;   
        }*/
        
        cout << "Data set " << tt++ << ":" << endl;
        for(int i=0; i<o; i++) {
            Point p; cin >> p.x >> p.y;
            cout << "     Citizen at (" << p.x << "," << p.y << ") is ";
            if (checkInside(CS, cs, p) && cs > 2)     
                cout << "safe." << endl;
            else if (checkInside(RS, rs, p) && rs > 2)
                cout << "robbed." << endl;
            else
                cout << "neither." << endl;
        }
        cout << endl;
        
    }   
}
