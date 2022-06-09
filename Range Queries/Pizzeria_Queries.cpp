#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int SIZE = 1e6 + 5;
const int INF = 2e18;
int n, t[2][SIZE], p[SIZE], q;
struct segment{
    void pull(int v){
        t[0][v] = min(t[0][v*2], t[0][v*2+1]);
        t[1][v] = min(t[1][v*2], t[1][v*2+1]);
    }
    void init(int v, int l, int r){
        if(l == r){
            t[0][v] = p[l] + l;
            t[1][v] = p[l] - l;
            return;
        }
        int m = (l + r)/2;
        init(v*2, l, m);
        init(v*2 +1, m+1, r);
        pull(v);
    }
    void update(int v, int l, int r, int pos, int val){
        if(l == r){
            p[l] = val;
            t[0][v] = val + l;
            t[1][v] = val - l;
            return;
        }
        int mm = (l + r)/2;
        if(pos <= mm){
            update(v*2, l, mm, pos, val);
        }else{
            update(v*2+1, mm+1, r, pos, val);
        }
        pull(v);
    }
    int get(int v, int l, int r, int a, int b, int id){
        //cout << v << endl;
        if(l > b || r < a){
            return INF;
        }
        if(a <= l && r <= b){
            return t[id][v];
        }
        int mm = (l + r)/2;
        return min(get(v*2, l, mm, a, b, id), get(v*2+1, mm+1, r, a, b, id));
    }   
}seg;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i<= n; i++){
        cin >> p[i];
    }
    seg.init(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 2){
            int x; cin >> x;
            cout << min(seg.get(1, 1, n, x, n, 0) - x, seg.get(1, 1, n, 1, x, 1) + x) << endl;
        }else{
            int a, b;
            cin >> a >> b;
            seg.update(1, 1, n, a, b);
        }
    }
}