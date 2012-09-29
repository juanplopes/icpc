//1332
//Genie Bomber
//Math;Geometry;Enclosing Circle
#include <iostream>
#include <cmath>         
#define EP 1e-6
using namespace std;

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    double dist(Point A) {
		return sqrt(pow(A.x-x,2)+pow(A.y-y,2));
	}
	
	Point middle(Point B) {
        return Point((x-B.x)/2, (y-B.y)/2);
    }

};

struct Circle {
    Point c; double r;
    Circle(Point c, double r) : c(c), r(r) { }
 
    Circle(Point p1, Point p2, double r) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
                    (p1.y - p2.y) * (p1.y - p2.y);
        double det = r*r / d2 - 0.25;
        double h = sqrt(det);

        this->c = Point((p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h,
                        (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h);
        this->r = r;
    }


    static bool invalid(Point p1, Point p2, double r) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
                    (p1.y - p2.y) * (p1.y - p2.y);
        double det = r*r / d2 - 0.25;
        return det < 0.0;
    }

   
    bool within(Point p) {
        return c.dist(p)-r < EP;
    }
};

Point P[106];

int best(Circle c1, int n) {
    int sum1 = 0;
    for(int k=0; k<n; k++) {
        if (c1.within(P[k]))
            sum1++;
    }
    return sum1;
}


int main() {
    int n, r, R;
    while(cin >> n) {
        for(int i=0; i<n; i++)
            cin >> P[i].x >> P[i].y;
        cin >> R >> r;
        R-=r;

        int maxx = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (i==j) {
                    maxx = max(maxx, best(Circle(P[i], R), n));
                } else if (!Circle::invalid(P[i], P[j], R)) {
                    maxx = max(maxx, best(Circle(P[i], P[j], R), n));
                    maxx = max(maxx, best(Circle(P[i], P[j], R), n));
                }
            }
        }

        cout << maxx << endl;
    }
}
