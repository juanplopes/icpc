//1249
//Euclid
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

struct Point {
    double x, y;
    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    double dist(Point& other) {
        return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
    }
};

struct Triangle {
    Point A, B, C;
    
    Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {}
    
    double area() {
        return (A.x * (B.y - C.y) - B.x * (A.y - C.y) + C.x * (A.y - B.y)) / 2;
    }
};

struct Segment {
    Point A, B;

    Segment(Point A, Point B) : A(A), B(B) {}
    
    double length() {
        return A.dist(B);
    }
    
    Segment scale(double factor) {
        return Segment(A, Point(A.x + (B.x-A.x)*factor, A.y + (B.y-A.y)*factor));
    }
    
    double angle(Segment& other) {
        return acos(((B.x-A.x)*(other.B.x - other.A.x)+(B.y-A.y)*(other.B.y - other.A.y))/(length()*other.length()));
    }
};


int main() {
    Point A, B, C, D, E, F;
    while(cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> E.x >> E.y >> F.x >> F.y, 
          A.x||A.y||B.x||B.y||C.x||C.y||D.x||D.y||E.x||E.y||F.x||F.y) {

        Segment AB(A, B), AC(A, C);

        double area = Triangle(D, E, F).area();

        double base = Segment(A, B).length();

        double height = area/base;
        double length = height / sin(AC.angle(AB));
        
        if (length < 0) length = -length;
        Point H = AC.scale(length / AC.length()).B;
        Point G(B.x+H.x-A.x, B.y+H.y-A.y);
        
//        cout << " " << AC.scale(height / AC.length()).A.x << " " << AC.scale(height / AC.length()).A.y << " " << AB.angle(AC)/3.14*180 << endl;
        cout << fixed << setprecision(3) << G.x << " " << G.y << " " << H.x << " " << H.y << endl;
    }    
}

