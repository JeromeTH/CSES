#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int SIZE = 1e6 + 5;
const int INF = 1e18;
int n, x[SIZE], m;
struct node{
    int mx, sum, lmx, rmx;
    node(int a = 0, int b = 0, int c = 0, int d= 0): mx(a), sum(b), lmx(c), rmx(d){;}
}t[SIZE];
node result;
inline void Max(int& a, int b){
    if(a < b) a = b;
}
struct segment{
    void upd(node &c, node a, node b){
        c.sum= a.sum + b.sum;
        c.mx = max(a.mx, b.mx);
        Max(c.mx, a.rmx+ b.lmx);
        c.lmx = max(a.lmx, a.sum + b.lmx);
        c.rmx= max(b.rmx, b.sum + a.rmx);
    }
    void init(int v, int l, int r){
        if(l == r){
            t[v] = node(x[l], x[l], x[l], x[l]);
            return;
        }
        int mm = (l + r)/2;
        init(v*2, l, mm);
        init(v*2 + 1, mm+1, r);
        upd(t[v], t[v*2], t[v*2+1]);
    }
    void update(int v, int l, int r, int pos, int val){
        if(l == r){
            t[v] = node(val, val, val, val);
            return;
        }
        int mm = (l + r)/2;
        if(pos <= mm){
            update(v*2, l, mm, pos, val);
        }else{
            update(v*2 + 1, mm+1, r, pos, val);
        }
        upd(t[v], t[v*2], t[v*2+1]);
    }
    void get(int v, int l, int r, int a, int b){
        if(l == a && r == b){
            upd(result, result, t[v]);
            return;
        }
        int mm = (l + r)/2;
        if(b <= mm){
            get(v*2, l, mm, a, b);
        }else if(a > mm){
            get(v*2 + 1, mm+1, r, a, b);
        }else{
            get(v*2, l, mm, a, mm);
            get(v*2+1, mm+1, r, mm+1, b);
        }
        return;
    }
}seg;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    seg.init(1, 1, n);
    while(m--){
        int a, b;
        cin  >> a >> b;
        seg.update(1, 1, n, a, b);
        result = node(-INF, -INF, -INF, -INF);
        seg.get(1, 1, n, 1, n);
        cout << max(0LL, result.mx) << endl;
    }
    return 0;
}