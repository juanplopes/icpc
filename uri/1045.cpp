//1045
//Triangle Types
//Misc;Beginner
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

double V[3];
int main() {
    while(cin >> V[0] >> V[1] >> V[2]) {
        sort(V, V+3, greater<double>());

        if (V[0] > V[1] + V[2])
            cout << "NAO FORMA TRIANGULO" << endl;
        if (V[0]*V[0] == V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO RETANGULO" << endl;
        if (V[0]*V[0] > V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO OBTUSANGULO" << endl;
        if (V[0]*V[0] < V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO ACUTANGULO" << endl;
        if (V[0] == V[1] && V[1] == V[2])
            cout << "TRIANGULO EQUILATERO" << endl;
        if (V[0] == V[1] ^ V[1] == V[2] ^ V[0] == V[2])
            cout << "TRIANGULO ISOSCELES" << endl;
    }
}
