//12487
//Midnight Cowboy
//Graphs;Markov Chain
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#define ull unsigned long long;
using namespace std;

int G[101][101], S[101];
double M[101], Q[101];;

int main() {
	int n, a, b, c;
	while(cin >> n >> a >> b >> c) {
		memset(M, 0, sizeof(M));
		memset(S, 0, sizeof(S));
		memset(G, 0, sizeof(G));
		
		for(int i=0;i<n-1;i++) {
			int a, b; cin >> a >> b;
			G[a][S[a]++] = b;
			G[b][S[b]++] = a;
		}
		
		M[a] = 1.0;
		for(int k=0;k<10000;k++) {
			memset(Q, 0, sizeof(Q));
			Q[b] = M[b];
			Q[c] = M[c];
			for(int i=1;i<=n;i++) {
//				cout << M[i] << " ";
				if (i==b || i==c) continue;
					
				for(int j=0;j<S[i];j++)
					Q[G[i][j]] += M[i] * 1.0/S[i];
			}
	//		cout << endl;
			
			swap(Q, M);
		}
		
		cout << fixed << setprecision(6) << M[b] << endl;
	}
}
