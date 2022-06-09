#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> g[SIZE];
int x[SIZE], t[SIZE], w[SIZE], n, q, vis[SIZE], p[SIZE];
pair<int, int> dur[SIZE];
struct segment{
    void pull(int v){
        t[v] = t[v*2] + t[v*2+1];
    }
    void init(int v, int l, int r){
        if(l == r){
            t[v] = x[w[l]];
            return;
        }
        int mm = (l + r)/2;
        init(v*2, l, mm);
        init(v*2+1, mm+1, r);
        pull(v);
    }
    void update(int v, int l, int r, int pos, int val){
        if(l == r){
            t[v] = val;
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
    int get(int v, int l, int r, int a, int b){
        if(l > b || r < a){
            return 0;
        }
        if(a <= l && r <= b){
            return t[v];
        }
        int mm = (l + r)/2;
        return get(v*2, l, mm, a, b) + get(v*2+1, mm+1, r, a, b);
    }
}seg;
int cnt=0;
void dfs(int k){
    dur[k].first = ++cnt;
    w[cnt] = k;
    p[k] = cnt;
    vis[k] = 1;
    for(auto i: g[k]){
        if(vis[i]) continue;
        dfs(i);
    }
    dur[k].second = cnt;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
   /* for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    for(int i =1; i<= n; i++){
        cout << dur[i].first << " " << dur[i].second << endl;
    }*/
   
    seg.init(1, 1, n);
    /*for(int i = 1;i <= 16; i++){
        cout << t[i] << " ";
    }
    cout << endl;*/
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;
            a = p[a];
            //cout << a << endl;
            seg.update(1, 1, n, a, b);
        }else{
            int a; cin >> a;
            cout << seg.get(1, 1, n, dur[a].first, dur[a].second) << endl;
        }
    }
    return 0;
}
// 中國信託銀行 本行營業部 901540277764  許家馨