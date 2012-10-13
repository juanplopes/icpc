//1251
//Repeated Substitution with Sed
//Graphs;Shortest Path;BFS
#include <iostream>
#include <queue>
#include <string>
#include <set>
#define MAX 1000
using namespace std;

struct Item {
    string s;
    int c;
    Item(string s, int c) : s(s), c(c) {}
};

string replace(string str, string from, string to) {
    if(from.empty())
        return str;
    int start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int n;
string A[MAX], B[MAX];

int main() {
    while(cin >> n, n) {
        for(int i=0; i<n; i++)
            cin >> A[i] >> B[i];
        string a, b;
        cin >> a >> b;

        queue<Item> Q;
        set<string> S;
        Q.push(Item(a, 0));
        
        int answer = -1;
        while(!Q.empty()) {
            Item e = Q.front(); Q.pop();
            if (e.s == b) {
                answer = e.c;
                break;
            }
            
            if (S.find(e.s) != S.end()) continue;
            S.insert(e.s);
            
            for(int i=0; i<n; i++) {
                string s = replace(e.s, A[i], B[i]);
                if (S.find(s) != S.end() || s.size() > 10) continue;
                Q.push(Item(s, e.c+1));
            }
        }
        
        cout << answer << endl;
        
    }
    
}
