//1021
//Banknotes and Coins
//Misc;Beginner
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double note(double x, string type, double note) {
    int n = 0;
    while(x >= note) {
        n+=1;
        x-=note;
    }
    cout << n << " " << type << "(s) de R$ " << fixed << setprecision(2) <<note << endl;
    return x;
}

int main() {
    double x;
    while(cin >> x) {
        cout << "NOTAS:" << endl;
        x = note(x, "nota", 100);
        x = note(x, "nota", 50);
        x = note(x, "nota", 20);
        x = note(x, "nota", 10);
        x = note(x, "nota", 5);
        x = note(x, "nota", 2);

        cout << "MOEDAS:" << endl;
        x = note(x, "moeda", 1);
        x = note(x, "moeda", 0.50);
        x = note(x, "moeda", 0.25);
        x = note(x, "moeda", 0.10);
        x = note(x, "moeda", 0.05);
        x = note(x, "moeda", 0.01);
        
    }
}
