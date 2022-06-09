#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1234567;
#define UnionFindSIZE 1234567
int ma = 1;
int discret[SIZE], dn;
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;   // 點 i 指向 i
            num[i] = discret[i + 1] - discret[i]; // 樹的點數 
            ma = max(ma, num[i]);
        }
    }
    int find(int x){
        while(x != d[x]) { x = d[x]; }
        return x;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x=find(x);
        y=find(y);
        if(x == y) { return 0; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        ma = max(ma, num[y]);
        d[x] = y;
        return 1;
    }
}U;
int p[SIZE];
int an[SIZE];
void solve() {
    int n, x;
    scanf("%d%d", &x, &n);
    discret[dn++] = 0;
    discret[dn++] = x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        discret[dn++] = p[i];
    }
    sort(discret, discret + dn);
    U.init(n + 1);
    an[n] = ma;
    for(int i = n ; i > 0; i--) {
        p[i] = lower_bound(discret, discret + dn, p[i]) - discret;
        U.uu(p[i] - 1, p[i]);
        an[i - 1] = ma;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d", an[i]);
        if(i < n) { printf(" "); }
        else { printf("\n"); }
    }
}
int main() {
    solve();
    return 0;
}