//1047
//Game Time with Minutes
//Misc;Beginner
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        int h = ((c-a)+24)%24;
        int m = d-b;
        if (m<0) { m+=60; h--; }
        
        cout << "O JOGO DUROU " << h << " HORA(S) E " << m << " MINUTO(S)" << endl;
    }
}
