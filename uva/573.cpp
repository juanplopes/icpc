//573
//The Snail
//Misc;Ad hoc
#include <iostream>
using namespace std;

int main() {
    int h,u,d,f;
    while(cin >> h >> u >> d >> f, h|u|d|f) {
        double current = 0, speed=u;
        
        for (int i=1;;i++) {
            current += speed;
            speed = max(0.0, speed-f/100.0*u);
            if (current > h) {
                cout << "success on day " << i << endl;
                break;
            } 
            current -= d;
            if (current < 0) {
                cout << "failure on day " << i << endl;
                break;
            }
        }
    }

    return 0;
}
