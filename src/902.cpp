//902
//Password Search
//Misc;STL map
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> T;

int main() {
    int n; string s;
    while(cin >> n >> s) {
        T.clear();
        
        int maxx=0, maxv=0;
        for(int i=0; i<=s.size()-n; i++){
            int v = ++T[s.substr(i, n)];
            if (v > maxv) {
                maxv = v;
                maxx = i;
            }
        }
        cout << s.substr(maxx, n) << endl;
    }
}
