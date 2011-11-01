//12172
//Matchsticks
//Misc;Greed
#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 101
using namespace std;

void printMax(int n) {
    if (n&1) { cout << "7"; n-=3; }
    for(;n;n-=2) cout << "1";
}

void printMin(int n) {
    switch(n) {
        case 2: cout << "1"; return;
        case 3: cout << "7"; return;
        case 4: cout << "4"; return; 
        case 5: cout << "2"; return;
        case 6: cout << "6"; return; 
    }
    
    switch(n%7) {
        case 1: cout << "10"; n-=8; break;
        case 2: cout << "1"; n-=2; break;
        case 3: 
            if (n==10) {
                cout << "22"; n-= 10; 
            } else{ 
                cout << "200"; n-=17;
            }
            break;
        case 4: cout << "20"; n-= 11; break;
        case 5: cout << "2"; n-= 5; break;
        case 6: cout << "6"; n-= 6; break;
    }
    for(;n;n-=7) cout << "8";
}

int main() {


    int n;
    int t; cin >> t; t=0;
    
    while(cin >> n) {
        printMin(n);
        cout << " ";
        printMax(n);
        cout << endl;
    }

    return 0;
}
