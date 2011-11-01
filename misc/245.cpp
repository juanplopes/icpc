//245
//Uncompress
//Misc;Linked List
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstring>
#include <cstdio>
#include <list>
#define MAX 1000
using namespace std;

list<string> W;
stringstream sin;
int curnum=0;
bool word=false, number=false;

void finishWord() {
    W.push_back(sin.str());
    sin.str("");
    word = false;
}

void finishNumber() {
    list<string>::iterator it = W.end();
    while(curnum--)
        it--;

    cout << *it;
    W.push_back(*it);
    W.erase(it);

    curnum = 0;
    number = false;
}
    
int main() {
    string s;
    
    while(getline(cin, s), s!="0") {
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                sin << c;
                word = true;
            } else if (word) finishWord();
            
            if (c >= '0' && c <= '9') {
                curnum *= 10; curnum += c-'0';
                number = true;
            } else if (number) finishNumber();
           
            if (!number)
                cout << c;
        }
        if (word) finishWord();
        if (number) finishNumber();
        
        cout << endl;
    }
}
