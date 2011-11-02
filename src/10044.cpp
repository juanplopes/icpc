//10044
//Erdos Number
//Graphs;Shortest Path;BFS
#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define MAX 5000
using namespace std;

vector<int> G[MAX];
int n, m;
bool V[MAX];
map<string, int> A;

struct Step {
    int x, v;
    Step() {}
    Step(int x, int v) : x(x), v(v) {}
};

queue<Step> Q;

int author(const string& a) {
    if (A.find(a) != A.end())
        return A[a];
    else
        return A[a] = A.size()-1;
}


char C[MAX];
void parseAuthors(const string& s) {
    vector<int> TA;
    int commas = 0, chars=0;
    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if (chars == 0 && c == ' ') continue;
        
        if ((c==',' || c==':') && ++commas == 2) {
            TA.push_back(author(string(C, chars)));
            chars = commas = 0;
        } else {
            C[chars++] = c;
        }
    }
    for(int i=0;i<TA.size(); i++) {
        for(int j=i+1;j<TA.size(); j++) {
            G[TA[i]].push_back(TA[j]);
            G[TA[j]].push_back(TA[i]);
        }
    }

}

int main() {
    string s;
    int t=0, tt;
    cin >> tt;
    while(t++ < tt) {
        cin >> n >> m;
        memset(G, 0, sizeof(G));
        A.clear();
        getline(cin, s);
        while(n--) {
            getline(cin, s);
            parseAuthors(s);
        }
        
        cout << "Scenario " << t << endl;
        for(int i=0;i<m;i++) {
            bool stop;
            memset(V, 0, sizeof(V));
            getline(cin, s);
            int b = author(s);
            Q = queue<Step>();
            Q.push(Step(author("Erdos, P."), 0));
            bool found = false;
            
            while(!Q.empty()) {
                Step it = Q.front(); Q.pop();
                if (it.x == b) {
                    cout << s << " " << it.v << endl;
                    found = true;
                    break;
                }
                
                V[it.x] = true;
                
                for(int i=0; i<G[it.x].size(); i++)
                    if (!V[G[it.x][i]]) Q.push(Step(G[it.x][i], it.v+1));
            }
            if (!found) cout << s << " infinity" << endl;
        }
    }
    return 0;
}
