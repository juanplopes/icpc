//1185
//Wall
//Math;Geometry;Enclosing Circle
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define PI 3.14159265
#define EP 1e-10
using namespace std;

struct Point {
    long double x, y;

    Point() {}
    Point(long double x, long double y) : x(x), y(y) {}
};

int P[107];

long double simpleCase(long double maxx, int n) {
    long double begin=maxx/2.0, end=50000001.0;
    while(abs(begin-end) > EP) {
        long double r = (begin+end)/2;
        long double angle = 0;
        long double sum = 0;
        Point A(r,0); 
        for(int i=0; i<n; i++) {
            angle += 2*asin(P[i]/(2.0*r));
            Point B(r*cos(angle), r*sin(angle));
            sum += (A.x + B.x) * (B.y - A.y);
            A = B;
        }
        sum /= 2;

        if (abs(angle-2*PI) < 1e-4)
            return sum;
        
        if (angle < 2*PI)
            end = r;
        else
            begin = r;
    }
    return 0.0;
}
long double complexCase(long double maxx, int n) {
    long double begin=maxx/2.0, end=50000001.0;
    while(abs(begin-end) > EP) {
        long double r = (begin+end)/2;
        long double angle = 2*asin(P[0]/(2.0*r));
        Point A(r*cos(angle),r*sin(angle)); 
        long double sum = (r + A.x) * (0 - A.y);
        for(int i=1; i<n; i++) {
            angle -= 2*asin(P[i]/(2.0*r));
            Point B(r*cos(angle), r*sin(angle));
            sum += (A.x + B.x) * (A.y - B.y);
            A = B;
        }
        sum /= 2;
        
        if (abs(angle) < EP)
            return sum;
        
        if (angle < 0)
            end = r;
        else
            begin = r;
    }
    return 0.0;
}

bool comp(int a, int b) {
    return a>b;
}

int main() {
    int n;
    while(cin >> n) {
        int maxx = 0, summ = 0;
        for(int i=0; i<n; i++) {
            cin >> P[i];
            maxx = max(maxx, P[i]);
            summ += P[i];
        }
            
        sort(P, P+n, comp);
        cout << fixed << setprecision(2) << max(simpleCase(maxx, n), complexCase(maxx, n)) << endl;

    }
}
