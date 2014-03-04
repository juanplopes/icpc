//1523
//Linear Parking Lot
//Misc;Beginner
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Car {
    int a, b;
    Car(int a, int b) : a(a), b(b) {}
};

stack<Car> S;
vector<Car> V;

int main() {
    int n, k;
    while(cin >> n >> k, n||k) {
        bool A = true;
        V.clear();
        
        for(int i=0; i<n; i++) {
            int a, b; cin >> a >> b;
            
            int time = 0;
            while(S.size() > 0 && a>=S.top().b) {
                A &= S.top().b >= time;
                time = S.top().b;
                S.pop();
            }
            
            A &= S.size() < k;
            S.push(Car(a, b));
        }
        
        int time = 0;
        while(S.size() > 0) {
            A &= S.top().b >= time;
            time = S.top().b;
            S.pop();
        }
        
        cout << (A?"Sim":"Nao") << endl;
    }
}

