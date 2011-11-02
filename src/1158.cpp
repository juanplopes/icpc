//1158
//CubesSquared
//Dynamic Programming;Knapsack;Infinite Items Knapsack
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int K[400001];
vector<int> W;

int main() {

    for(int i=1; i*i*i<=400000; i++)
        W.push_back(i*i*i);
    
    for(int a=1, i=1; a<=400000; i++, a+=i*i)
        W.push_back(a);  
  
    memset(K, 0x3f, sizeof(K));
    K[0] = 0;
    for(int i=0; i<W.size(); i++)
        for(int j=W[i]; j<=400000; j++)
            K[j] = min(K[j], K[j-W[i]]+1);
          
    int n;
    while(cin >> n, n!=-1)
        cout << K[n] << endl;   
   
    return 0;
}
