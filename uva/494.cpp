//494
//Kindergarten Counting Game
//Misc;Ad hoc
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        bool inside = false;
        int words = 0;
        for(int i=0; i<s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                inside = true;
            } else if (inside) {
                inside = false;
                words++;
            }
        }
        if (inside) words++;
        cout << words << endl;
    }
    
}
