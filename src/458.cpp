//458
//The Decoder
//Misc;Ad hoc
#include <iostream>
#include <string>
using namespace std;

int main() {
    for(string s; cin>>s;) {
        for(int i=0; i<s.size(); i++) 
            s[i]-=7;
        cout << s << endl;
    }
}
