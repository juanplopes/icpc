//10189
//Minesweeper
//Misc;Ad hoc
#include <iostream>
#include <cstring>
using namespace std;

char T[200][200];
int N[200][200];
int n, m, t=0;

void add(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m) return;
    N[i][j]++;
}

int main() {
    while(cin >> n >> m, n|m) {
        memset(N, 0, sizeof(N));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> T[i][j];
                if (T[i][j] == '*') {
                    add(i-1, j-1);
                    add(i-1, j);
                    add(i-1, j+1);
                    add(i, j-1);
                    add(i, j+1);
                    add(i+1, j-1);
                    add(i+1, j);
                    add(i+1, j+1);
                }
            }
        }
    
        if (t++>0) cout << endl;
        cout << "Field #" << t << ":" << endl;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (T[i][j] == '*')
                    cout << T[i][j];
                else
                    cout << N[i][j];
            }
            cout << endl;
        }
    }
}
