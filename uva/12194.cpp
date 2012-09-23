//12194
//Isosceles Triangles
//Math;Geometry
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1010
using namespace std;

int X[MAX], Y[MAX];
long T[MAX][MAX];
int C[MAX];

inline long sqr(long v) { return v*v; }

int main(){
    int n;
    while(scanf("%d", &n), n) {
        memset(C, 0, sizeof(C));
        
        for(int i=0; i<n; i++)
            scanf("%d %d", &X[i], &Y[i]);
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                T[i][C[i]++] = sqr(X[i]-X[j])+sqr(Y[i]-Y[j]);
            sort(T[i], T[i]+C[i]);
            long last=-1L;
            int cnt=0;
            for(int j=0; j<C[i]; j++) {
                if (T[i][j] != last) {
                    sum += cnt*(cnt-1)/2;
                    cnt = 0;
                }
                last = T[i][j];
                cnt++;
            }
            sum += cnt*(cnt-1)/2;
        }

        printf("%d\n", sum);
    }
    
}
