//12483
//Toboggan of Marbles
//Math;Geometry;Point to Line
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#define ull unsigned long long;
using namespace std;

struct Point {
	double x, y;
	
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	
	double dist(Point A) {
		return sqrt(pow(A.x-x,2)+pow(A.y-y,2));
	}
	
	double toLine(Point A, Point B) {
		double scale = ((x - A.x) * (B.x - A.x) + (y-A.y)*(B.y-A.y)) / 
					   ((B.x - A.x) * (B.x - A.x) + (B.y-A.y)*(B.y-A.y));
					   
		return dist(Point(A.x + scale*(B.x-A.x), A.y + scale * (B.y-A.y)));
	}
	
	double toSegment(Point A, Point B) {
		if ((x - A.x) * (B.x - A.x) + (y-A.y)*(B.y-A.y) <= 1e-6)
			return dist(A);

		if ((x - B.x) * (A.x - B.x) + (y-B.y)*(A.y-B.y) <= 1e-6)
			return dist(B);

		return toLine(A, B);
	}
};

int main() {
	int n, L, H;
	while(cin >> n >> L >> H) {
		Point pa, pb;
		int ya, yb;
		
		double minn = 100000000.0;
		for(int i=0;i<n;i++) {
			cin >> ya >> pa.x >> pa.y;

			int lado = i&1?L:0;
			int outroLado = i&1?0:L;
			
//			cout << " " << pa.x << " " << pa.y << "^" << outroLado;
			minn = min(minn, pa.toSegment(Point(outroLado, 0), Point(outroLado, H)));
			
			//cout << " " << pa.toSegment(Point(outroLado, 0), Point(outroLado, H));
			if (i>0) {
				minn = min(minn, pb.toSegment(Point(lado, ya), pa));
	//			cout << " " << pb.toSegment(Point(lado, ya), pa);
			}
			//cout << endl;
				

			yb = ya;
			pb = pa;
		}
		cout << fixed << setprecision(2) << minn << endl;
		
	}
	
}
