//10420
//List of Conquests
//Misc;STL map
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#define MAX 105
using namespace std;

map<string, int> women;
int main() {
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        women[s]++;
        getline(cin, s);
    }

    for(map<string, int>::const_iterator it = women.begin(); it != women.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
