//1200
//A DP Problem
//Misc;String parsing  
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getSign(string& s, int &i) {
    if (s[i] == '+') { i++; return 1; }
    if (s[i] == '-') { i++; return -1; }
    return 1;
}

int getNumber(string& s, int& i, bool& got) {
    int result = 0;
    while(s[i] >='0' && s[i] <= '9') {
        result = result*10 + (s[i]-'0');
        i++;
        got = true;
    }   
    return result;
}

bool getX(string& s, int& i) {
    return i<s.size() && s[i] == 'x' && ++i;
}

bool willChange(string& s, int& i) {
    return i<s.size() && s[i] == '=' && ++i;
}
    

int main()
{
    int t;
    string s;
    cin >> t;
    
    while(cin >> s) {
        int i=0, A=0, B=0, masterSign = 1;
        while(i<s.size()) {
            int sign = getSign(s, i);   
            bool got = false;
            int number = getNumber(s, i, got);
            bool isX = getX(s, i);
            if (isX && !got) number = 1;
           // cout << masterSign << " " << sign << " " << number << " " << isX << endl;

            if (isX)
                B += -1*masterSign*sign*number;
            else
                A += masterSign*sign*number; 
            if (willChange(s, i)) masterSign *= -1;
        }
        if (A==0 && B==0) {
            cout << "IDENTITY" << endl;
        } else if (B==0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << (int)floor(((double)A/B))<< endl;
        }
  
    }
    
    return 0;
}
