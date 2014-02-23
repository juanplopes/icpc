//1046
//Game Time
//Misc;Beginner
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b) {
        cout << "O JOGO DUROU " << ((b-a)+24)%24 << " HORA(S)" << endl;
    }
}
