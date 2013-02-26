//1013
//The Greatest
//Misc;Beginner
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        cout << max(a, max(b, c)) << " eh o maior" << endl;
    }
}
