#include <iostream>
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

int main() {
    string s1, s2, tmps;
    int t=0, tt;
    cin >> tt;
    while(t++ < tt) {
        cin >> n >> m;
        memset(G, 0, sizeof(G));
        A.clear();

        while(n--) {
            vector<int> TA;
            while(true) {
                cin >> s1 >> s2;
                bool stop = s2[s2.size()-1] == ':';
                s2.erase(s2.size()-1);
                TA.push_back(author(s1 + " " + s2));
                if (stop) { getline(cin, s1); break; }
            }
            for(int i=0;i<TA.size();i++)
                for(int j=0;j<TA.size();j++)
                    if (i!=j) G[TA[i]][TA[j]] = true;
        }
        
        cout << "Scenario " << t << endl;
        for(int i=0;i<m;i++) {
            memset(V, 0, sizeof(V));
            cin >> s1 >> s2;
            int b = author(s1 + " " + s2);
            Q = vector<Step>();
            Q.push_back(Step(author("Erdos, P."), 0));
            
            int ptr = 0;
            while(ptr < Q.size()) {
                Step it = Q[ptr];
                if (it.x == b) {
                    cout << s1 << " " << s2 << " " << it.v << endl;
                    break;
                }
                
                if (V[it.x]) { ptr++; continue; }
                V[it.x] = true;
                
                for(int i=0; i<A.size(); i++)
                    if (G[it.x][i]) Q.push_back(Step(i,it.v+1));
                
                ptr++;
            }
            if (ptr == Q.size()) cout << s1 << " " << s2 << " infinity" << endl;
        }
    }
}
