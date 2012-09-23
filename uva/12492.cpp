//12492
//Rubik Cycle
//Misc;Ad hoc
#include <iostream>
#include <string>
#define MAX 200010
using namespace std;

int T[54];

void rotate(int a, int b, int c, int d, int e, int f, int g, int h) {
    int x = T[h], y = T[g];
    T[h] = T[f];
    T[g] = T[e];

    T[f] = T[d];
    T[e] = T[c];

    T[d] = T[b];
    T[c] = T[a];

    T[b] = x;
    T[a] = y;
}

void adjust(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int x = T[j], y = T[k], z = T[l];
    
    T[j] = T[g];
    T[k] = T[h];
    T[l] = T[i];

    T[g] = T[d];
    T[h] = T[e];
    T[i] = T[f];
    
    T[d] = T[a];
    T[e] = T[b];
    T[f] = T[c];

    T[a] = x;
    T[b] = y;
    T[c] = z;
}

void F() {
    rotate(0, 1, 2, 5, 8, 7, 6, 3);
    adjust(33, 34, 35, 45, 48, 51, 11, 10, 9, 44, 41, 38);
}

void B() {
    rotate(26, 25, 24, 21, 18, 19, 20, 23);
    adjust(29, 28, 27, 36, 39, 42, 15, 16, 17, 53, 50, 47);
}

void L() {
    rotate(36, 37, 38, 41, 44, 43, 42, 39);
    adjust(0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33);
}

void R() {
    rotate(45, 46, 47, 50, 53, 52, 51, 48);
    adjust(8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11);
}

void U() {
    rotate(27, 28, 29, 32, 35, 34, 33, 30);
    adjust(2, 1, 0, 38, 37, 36, 24, 25, 26, 47, 46, 45);
}

void D() {
    rotate(9, 10, 11, 14, 17, 16, 15, 12);
    adjust(6, 7, 8, 51, 52, 53, 20, 19, 18, 42, 43, 44);
}


bool ok() {
    for(int i=0; i<54; i++) {
        if (T[i] != i) return false;
    }
    return true;
}

int main() {
    string s;
    while(cin >> s) {
        for(int i=0; i<54; i++)
            T[i] = i;
            
        int result = 0;
        do {
            for(int i=0;i<s.size();i++) {
                switch(s[i]) {
                    case 'F': F(); break;
                    case 'B': B(); break;
                    case 'R': R(); break;
                    case 'L': L(); break;
                    case 'U': U(); break;
                    case 'D': D(); break;
                    case 'f': F(); F(); F(); break;
                    case 'b': B(); B(); B(); break;
                    case 'r': R(); R(); R(); break;
                    case 'l': L(); L(); L(); break;
                    case 'u': U(); U(); U(); break;
                    case 'd': D(); D(); D(); break;
                }
            }
            result++;
        } while (!ok());
        cout << result << endl;
    }
}
