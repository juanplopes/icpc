//1040
//Average 3
//Misc;Beginner
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double n1, n2, n3, n4, n5;
    while(cin >> n1 >> n2 >> n3 >> n4) {
        double media = (2*n1 + 3*n2 + 4*n3 + n4)/10;
        cout << fixed << setprecision(1);
        cout << "Media: " << media << endl;
        if (media >= 7.0) {
            cout << "Aluno aprovado." << endl;
        } else if (media < 5) {
            cout << "Aluno reprovado." << endl;
        } else {
            cin >> n5;
            cout << "Aluno em exame." << endl;
            cout << "Nota do exame: " << n5 << endl;
            
            
            media = (media + n5)/2;
            if (media >= 5.0) {
                cout << "Aluno aprovado." << endl;
            } else {
                cout << "Aluno reprovado." << endl;
            }
            cout << "Media final: " << media << endl;
        }

    }
}
