//1203
//Argus
//Misc;Priority queue
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define SZ 3200

struct Item{
  int p, q, b;
  
  Item() {}
  Item(int q, int p) : p(p), q(q), b(p) {}
  Item(int q, int p, int b) : p(p), q(q), b(b) {}
   
  inline bool operator < (const Item &d) const{
    if(this->p==d.p) return d.q<this->q;
    return this->p>d.p;
  }
  
  Item next() {
    return Item(q, p+b, b);      
  }
  
};

priority_queue<Item> Q;
int q, p;

int main(void) {
  string s;
  int q, p, k;
  
  while(cin >> s, s!="#") {
    cin >> q >> p;
    Q.push(Item(q, p));      
  }
  
  cin >> k;
  for(int i=0; i<k; ++i) {
    Item item = Q.top(); Q.pop();
    cout << item.q << endl;
    Q.push(item.next());
  }

  return 0;
}
