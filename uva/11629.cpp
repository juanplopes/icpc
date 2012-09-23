//11629
//Ballot evaluation
//Misc;STL map
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map<string, int> P;

int main() {
    int n, g;
    while(cin >> n >> g) {
        P.clear();
        for(int i=0; i<n; i++) {
            string s; int a, b; 
            cin >> s >> a; cin.get(); cin >> b;
            P[s] = a*10+b;
        }
        
        for(int i=1; i<=g; i++) {
            string s = "+"; int d=0; int r;
            
            while(s=="+") {
                cin >> s; 
                d += P[s];
                cin >> s;
            }
            cin >> r; r*=10;
            
            bool result;
            if ( s=="<") result = d < r;
            if ( s=="<=") result = d <= r;
            if ( s==">") result = d > r;
            if ( s==">=") result = d >= r;
            if ( s=="=") result = d == r;
            cout << "Guess #" << i << " was " << (result?"correct":"incorrect") << "." << endl;
        }
        
    }
}
