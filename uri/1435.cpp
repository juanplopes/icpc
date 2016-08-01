//1435
//Square Matrix I
//Misc;Beginner
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int number = min(min(i+1, j+1), min(n-i, n-j));
                if (j>0) cout << " ";
                
                cout << right << setw(3) << number;
            }
            cout << endl;
        }
        cout << endl;
    }
}
