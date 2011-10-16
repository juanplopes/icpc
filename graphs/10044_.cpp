#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <map>
#define MAX 400
using namespace std;

int G[MAX][MAX], n, m;
bool V[MAX];
map<string, int> A;

struct Step {
    int x, v;
    Step() {}
    Step(int x, int v) : x(x), v(v) {}
};

vector<Step> Q;

int author(const string& a) {
    if (A.find(a) != A.end())
        return A[a];
    else
        return A[a] = A.size()-1;
}

bool getauthor(istream& ist, string& s, bool& stop) {
    string tmp;
    stringstream str;
    while(ist.peek() == ' ') ist.ignore();
    
    char c;
    int commas=0;
    while(ist) {
        c = ist.get();
        if (c==',') commas++;
        if (c==':' || commas==2) break;
        str << c;
    }
    s = str.str();
    if (c == ':') { getline(ist, tmp); stop = true; }
    
    return commas > 0;
}

int main() {
    string s;
    int t=0, tt;
    cin >> tt;
    while(t++ < tt) {
        cin >> n >> m;
        memset(G, 0, sizeof(G));
        A.clear();

        while(n--) {
            vector<int> TA;
            bool stop = false;
            while(!stop) {
                if (getauthor(cin, s, stop)) {
                    if (stop) cout << "***";
                    TA.push_back(author(s));
                    cout << s << ":::";
                }
            }
            for(int i=0;i<TA.size();i++)
                for(int j=0;j<TA.size();j++)
                    if (i!=j) G[TA[i]][TA[j]] = true;
        }
        
        cout << "Scenario " << t << endl;
        for(int i=0;i<m;i++) {
            bool stop;
            memset(V, 0, sizeof(V));
            getauthor(cin, s, stop);
            int b = author(s);
            Q = vector<Step>();
            Q.push_back(Step(author("Erdos, P."), 0));
            
            int ptr = 0;
            while(ptr < Q.size()) {
                Step it = Q[ptr];
                if (it.x == b) {
                    cout << s << " " << it.v << endl;
                    break;
                }
                
                if (V[it.x]) { ptr++; continue; }
                V[it.x] = true;
                
                for(int i=0; i<A.size(); i++)
                    if (G[it.x][i]) Q.push_back(Step(i,it.v+1));
                
                ptr++;
            }
            if (ptr == Q.size()) cout << s << " infinity" << endl;
        }
    }
}
