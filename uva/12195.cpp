//12195
//Jingle Composing
//Misc;Ad hoc
#include <iostream>
#include <string>
using namespace std;

int duration(char c) {
    switch(c) {
        case 'W': return 64;
        case 'H': return 32;
        case 'Q': return 16;
        case 'E': return 8;
        case 'S': return 4;
        case 'T': return 2;
        case 'X': return 1;
    }
}

int main() {
    string s;
    while(cin >> s, s!="*") {
        int d=0, r=0;
        for(int i=1; i<s.size(); i++) {
            if (s[i] == '/') {
                if (d==64) r++;
                d = 0;
                continue;
            }
            d+=duration(s[i]);
        }
        cout << r << endl;
    }

    return 0;
}
