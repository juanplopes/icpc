//1050
//DDD
//Misc;Beginner
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int a;
    while(cin >> a) {
        if (a==61)
            cout << "Brasilia" << endl;
        else if (a==71)
            cout << "Salvador" << endl;
        else if (a==11)
            cout << "Sao Paulo" << endl;
        else if (a==21)
            cout << "Rio de Janeiro" << endl;
        else if (a==32)
            cout << "Juiz de Fora" << endl;
        else if (a==19)
            cout << "Campinas" << endl;
        else if (a==27)
            cout << "Vitoria" << endl;
        else if (a==31)
            cout << "Belo Horizonte" << endl;
        else
            cout << "DDD not found" << endl;

    }
}
