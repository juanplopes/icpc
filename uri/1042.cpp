//1042
//Simple Sort
//Misc;Beginner
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int V[3];
int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        V[0] = a;
        V[1] = b;
        V[2] = c;
        sort(V, V+3);
        
        for(int i=0; i<3; i++)
            cout << V[i] << endl;
        cout << endl;
        
        cout << a << endl << b << endl << c << endl;
        
    }
}
