//160
//Factors and Factorials
//Misc;Ad hoc
#include <iostream>
#include <iomanip>
using namespace std;

int W[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }, wn = 25;
int T[101][25];

int main() {
    for(int i=2; i<=100; i++) {
        int p = i;
        for(int j=0; j<wn; j++)
            T[i][j] = T[i-1][j];
        
        for(int j=0; j<wn && p>1; j++) {
            while(p%W[j]==0) {
                p/=W[j];
                T[i][j]++;
            }
        }
    }

    int n;
    while(cin >> n, n) {
        cout <<  setw(3) << right << n << "! =";
        int count = 0;
        for(int i=0; i<wn; i++) {
            if (T[n][i] == 0) break;
            if (++count > 15) {
                count = 1;
                cout << endl << "      ";
            }
            cout << setw(3) << right << T[n][i];
        }
        cout << endl;
    }
    
    return 0;
}
