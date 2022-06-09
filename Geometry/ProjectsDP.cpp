#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define pii pair<int , int> 
const int SIZE = 2e5 + 5;
int n, p[SIZE], c[SIZE*2], dp[2*SIZE + 5];
struct node{
    int l, r, v;
    bool operator <(const node &b)const{
        return r < b.r;
    }
}a[SIZE];
vector<node> g[2*SIZE+5];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);i
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r >> a[i].v;
        c[i] = a[i].l;
        c[n + i] = a[i].r;
    }
    sort(c, c + 2*n);
    int m = unique(c, c + 2*n) - c;
    for(int i  =0; i < n; i++){
        a[i].l = lower_bound(c, c + m, a[i].l) - c + 1;
        a[i].r = lower_bound(c, c + m, a[i].r) - c + 1;
        g[a[i].r].push_back(a[i]);
        //cout << a[i].l << " " << a[i].r << " " << a[i].v << endl;
    }
    for(int i = 1; i <= 2*n + 1; i++){
        dp[i] = dp[i -1 ];
        for(auto j: g[i]){
            dp[i] = max(dp[i], dp[j.l - 1] + j.v);
        }
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << dp[2*n+1] << endl;
}