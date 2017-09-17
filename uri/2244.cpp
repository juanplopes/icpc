//2244
//Olympic Games
//Misc;Convex-Hull Trick
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 100001
using namespace std;

struct Frac {
    long long a, b;
    Frac() {}
    Frac(long long a) : a(a), b(1) { }
    Frac(long long a, long long b) : a(b<0?-a:a), b(b<0?-b:b) {}   
    
    inline bool operator<(const Frac& other) const {
        return a*other.b < other.a*b;
    } 
    
    inline bool operator<=(const Frac& other) const {
        return a*other.b <= other.a*b;
    }
};

struct Line {
    long long i, a, b;
    Frac x;
    
    inline bool operator<(const Line& other) const {
        if (a!=other.a) return a < other.a;
        return b > other.b;
    }
    
    Frac intersect(const Line& other) const {
        return Frac(b-other.b, other.a-a);
    }
};

Line H[MAX], C[MAX];
vector<Line> HH, CC;
set<long long> S;

void convex_hull_trick(int n, Line* X, vector<Line>& XX) {
    for(int i=0; i<n; i++) {
        if (XX.size() && X[i].a == XX.back().a) continue;
        
        while(XX.size() && X[i].intersect(XX.back()) <= XX.back().x) {
            XX.pop_back();
        }
        XX.push_back(X[i]);
        if (XX.size() > 1)
            XX.back().x = XX.back().intersect(XX[XX.size()-2]);
        
    }
}

bool find_max_compare(const Frac& value, const Line& line) {
    return value < line.x;
}

int find_max(vector<Line>& XX, Frac x) {
    vector<Line>::iterator it = upper_bound(XX.begin(), XX.end(), x, find_max_compare);
    it--;
    return it->i;
}

void fill_set(vector<Line>& AA, vector<Line>& BB) {
    for(int i=0; i<AA.size(); i++) {
        if (AA[i].i == find_max(BB, AA[i].x))
            S.insert(AA[i].i);
            
        Frac xEnd = i+1<AA.size() ? Frac(AA[i+1].x.a*100000-1, AA[i+1].x.b*100000) : Frac(10000000);
        if (AA[i].i == find_max(BB, xEnd))
            S.insert(AA[i].i);
    }
}

void debugit(vector<Line>& V) {
    for(int i=0; i<V.size(); i++) {
        cout << " " << V[i].i << " " << V[i].a << " " << V[i].b << " " << V[i].x.a << "/" << V[i].x.b << endl; 
    }
    cout << endl;
}

int main() {
    int n;
    
    while(cin >> n) {
        HH.clear();
        CC.clear();
        S.clear();
        
        for(int i=0; i<n; i++) {
            C[i].i = H[i].i = i;
            C[i].x = H[i].x = Frac(0);
            cin >> H[i].b >> H[i].a >> C[i].b >> C[i].a;
            C[i].b = -C[i].b;
            C[i].a = -C[i].a;
        }
        
        sort(H, H+n);
        sort(C, C+n);
        
        convex_hull_trick(n, H, HH);
        convex_hull_trick(n, C, CC);
        
        //cout << " " << find_max(HH, Frac(0)) << " " << find_max(HH, Frac(1, 5)) << " " << find_max(HH, Frac(3, 10)) << " " << find_max(HH, Frac(10000000)) << endl;
        
        //debugit(HH);
        //debugit(CC);
        //cout << endl;
        
        
        fill_set(HH, CC);
        fill_set(CC, HH);
        
        cout << S.size() << endl;
    }
}
