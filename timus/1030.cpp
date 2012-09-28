//1030
//Titanic
//Math;Geometry;Great-Circle Distance
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#define PI 3.14159265
using namespace std;

double distance(double r, double x1, double y1, double x2, double y2) {
    return r*acos(sin(x1)*sin(x2) + cos(x1)*cos(x2)*cos(fabs(y1-y2)));
}

double readCoord() {
    int a1, a2, a3; char c; string s;
    cin >> a1 >> c >> a2 >> c >> a3 >> c >> s;
    double ret = (a1 + a2/60.0 + a3/3600.0) / 180.0 * PI;
    if (s=="WL." || s=="SL")
        ret = -ret;
    return ret;
}

double round(double d)
{
  return floor(d + 0.5);
}

int main() {
    string s;
    
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    
    double X1 = readCoord();
    cin >> s;
    double Y1 = readCoord();
    getline(cin, s);
    getline(cin, s);
    double X2 = readCoord();
    cin >> s;
    double Y2 = readCoord();

    double d = distance(6875.0/2, X1, Y1, X2, Y2);
    cout << "The distance to the iceberg: " << fixed << setprecision(2) << round(d*100)/100.0 << " miles." << endl;
    if (d < 99.995)
        cout << "DANGER!" << endl;

}
