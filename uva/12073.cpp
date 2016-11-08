//12073
//Altitude Triangle
//Math;Geometry
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#define EPS 1e-6
using namespace std;

struct Point {
    double x, y;
    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    double dist(Point& other) {
        return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
    }
};


struct Line {
    double a, b, c;
    Line(Point A, Point B) {
        if (A.x == B.x) {
            a = 1; b = 0; c = -A.x;
        } else {
            a = -(A.y-B.y)/(A.x-B.x);
            b = 1;
            c = - (a*A.x) - (b*A.y);
        }
    }
    
    Line(Point A, double m) {
        a = -m;
        b = 1;
        c = -(a*A.x + b*A.y);
    }
    
    Line perpendicular(Point& other) {
        if (abs(b) < EPS) {
            return Line(other, Point(-c, other.y));
        } else if (abs(a) < EPS) {
            return Line(other, Point(other.x, -c));
        } else {
            return Line(other, 1/a);
        }
    }    
    
    Point intersection(Line& r2) {
        Line r1 = *this;
        double x = (r2.b*r1.c-r1.b*r2.c)/(r2.a*r1.b-r1.a*r2.b);
        return Point(x, abs(b) > EPS ? -(r1.a*x+r1.c)/r1.b : -(r2.a*x+r2.c)/r2.b);
    }
};

struct Segment {
    Point A, B;

    Segment(Point A, Point B) : A(A), B(B) {}
    
    double length() {
        return A.dist(B);
    }
    
    Segment normalize() {
        return scale(1/length());
    }
    
    Segment scale(double factor) {
        return Segment(A, Point(A.x + (B.x-A.x)*factor, A.y + (B.y-A.y)*factor));
    }
    
    Line bisect(Point C) {
        double thisLength = length();
        double otherLength = Segment(A, C).length();

        return Line(A, Point(A.x + otherLength * (B.x-A.x) + thisLength * (C.x-A.x), 
                             A.y + otherLength * (B.y-A.y) + thisLength * (C.y-A.y)));
    }
};


int main() {
    int test = 0;

    Point A, B, C;
    while(cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y, A.x||A.y||B.x||B.y||C.x||C.y) {
        Segment AB(A, B), BC(B, C), CA(C, A);
        
        Line LA = AB.bisect(C), LB = BC.bisect(A), LC = CA.bisect(B);
        
        Line FE = LA.perpendicular(A), ED = LC.perpendicular(C), DF = LB.perpendicular(B);

        Point D = ED.intersection(DF), E = ED.intersection(FE), F = FE.intersection(DF);

        cout << "Case " << ++test << ":" << endl;
        cout << fixed << setprecision(3);
        cout << D.x << " " << D.y << endl;
        cout << E.x << " " << E.y << endl;
        cout << F.x << " " << F.y << endl;
    }    
}

