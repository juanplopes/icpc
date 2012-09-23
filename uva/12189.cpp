//12189
//Dinner Hall
//Misc;Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int s; char t;
    Event() {}
    Event(int s, char t) : s(s), t(t) {}
    int entry() { return t=='E'?1:0; }
    int exit() { return t=='X'?1:0; }
    int unknown() { return t=='?'?1:0; }
};

bool compare(const Event& a, const Event& b) {
    return a.s < b.s;
}

vector<Event> V;

int main() {
    int n;
    while(cin >> n, n) {
        int entries=0, exits=0, unknowns=0;
        int a, b, c; char t;
        V.clear();
        for(int i=0; i<n; i++) {
            cin >> a >> t >> b >> t >> c >> t;
            Event e = Event(a*60*60+b*60+c, t);
            entries += e.entry();
            exits += e.exit();
            unknowns += e.unknown();
            V.push_back(e);
        }
        sort(V.begin(), V.end(), compare);
        
        int maxEntries = (unknowns-(entries-exits))/2;
        int maxx = 0, current=0;
        for(int i=0; i<V.size(); i++) {
            if (V[i].entry()) current++;
            if (V[i].exit()) current--;
            if (V[i].unknown()) { 
                if (maxEntries) { current++; maxEntries--; }
                else { current--; }
            }
            maxx = max(maxx, current);
        }
        cout << maxx << endl;
    }
}
