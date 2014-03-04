//1521
//The Guilty
//Misc;Beginner
#include <iostream>
using namespace std;

int T[100];

int main() {
    int n, k;
    while(cin >> n, n) {
        for(int i=0; i<n; i++)
            cin >> T[i];
        cin >> k;
        while(T[k-1] != k) {
            k = T[k-1];
        }
        cout << k << endl;

    }
}

