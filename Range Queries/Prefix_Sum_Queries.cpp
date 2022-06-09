#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int SIZE = 2e5 + 1;
const int INF = 1e9 + 7;
int t[SIZE], s[3*SIZE], g[SIZE], n, q;
struct Fenwick{
    int p(int x){
        return x & (-x);
    }
    void init(int n){
        for(int x = 1; x <= n; x++){
            t[x] = g[x];
            int y = x - p(x);
            for(int i = x - 1; i > y; i -= p(i)){
                t[x] += t[i];
            }
        }
    }
    int get(int x){
        int res =0;
        while(x){
            res += t[x];
            x -= p(x);
        }
        return res;
    }
    void add(int x, int y){
        while(x < SIZE){
            t[x] += y;
            x += p(x);
        }
    }
}f;
struct segment{// one indexed
    void build(int v, int l, int r){
        if (l == r){
            s[v] = f.get(l);
        }else{
            int mm = l + (r - l)/2;
            build(v*2, l, mm);
            build(v*2+1, mm+1, r);
            s[v] = max(s[v*2], s[v*2+1]);
        }
    }
    void update(int v, int l, int r, int a, int b, int add){// target a, b now at l, r
        if (a > b) return;
        if (l == a && r == b){
            s[v] += add;
        }else{
            int mm = l + (r - l)/2;
            update(v*2, l, mm, a, min(mm, b), add);
            update(v*2+1, mm+1, r, max(a, mm+1), b, add);
            s[v] = max(s[v*2], s[v*2+1]);
        }
    }
    int get(int v, int l, int r, int a, int b){
        if (a > b)return -INF;
        if (l == a && r == b){
            return s[v];
        }else{
            int mm = (l + r)/2;
            int q= get(v*2, l, mm, a, min(mm, b));
            q = max(q, get(v*2+1, mm+1,r, max(mm+1, a), b));
            return q;
        }
    }
}seg;
void outseg(){
    int cur = 1;
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j < 1 << i; j++){
            cout << s[cur++] << " ";
        }
        cout << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >>g[i];
    }
    f.init(n);
    seg.build(1, 1, n);
    while(q--){
        int type; cin >> type;
        int a, b; cin >> a >> b;
        if (type == 1){
            int d = b - g[a];
            g[a] = b;
            f.add(a, d);
            seg.update(1, 1, n, a, n, d);
            for(int i = 1; i <= n; i++){
                cout << f.get(i) << " ";
            }
            cout << endl;
            outseg();
        }else{
            cout << seg.get(1, 1, n, a, b) - f.get(a - 1) << endl;
        }
    }
    return 0;
}