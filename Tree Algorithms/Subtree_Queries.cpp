#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int SIZE = 9e5 + 1;
int x[SIZE], t[SIZE], w[SIZE];
int n, q;
struct segment_tree{
    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = x[w[tl]];
        }else{
            int tm = (tl + tr)/2;
            build(v*2, tl, tm);
            build(v*2+1, tm + 1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    int sum(int a, int b, int k, int l, int r){// target [a, b] now at l, r 
        if (a > b) return 0;
        if (l == a && r == b){
            return t[k];
        }
        int m = (l + r)/2;
        return sum(a, min(m, b), k*2, l, m) + sum(max(a, m+1), b, k*2+1, m + 1, r);
    }
    void update(int v, int l, int r, int pos, int new_val){
        if (l == r){
            t[v] = new_val;
        }else{
            int tm = (l + r)/2;
            if (pos <= tm){
                update(v*2, l, tm, pos, new_val);
            }else{
                update(v*2+1, tm + 1, r, pos, new_val);
            }
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }
}s;
vector<int> g[SIZE];
pair<int, int> dur[SIZE];
int cnt = 0, used[SIZE];
void dfs(int k){
    dur[k].first = ++cnt;
    w[cnt] = k;
    used[k] = 1;
    for(auto i: g[k]){ 
        if(used[i]) continue;
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
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    /*for(int i = 1; i <= n; i++){
        cout << w[i] <<  " ";
    }
    cout << endl;*/
    s.build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;
            s.update(1, 1, n, a, b);
        }else{
            int a; cin >> a;
            cout << s.sum(dur[a].first, dur[a].second, 1, 1 ,n) << endl;
        }
    }
    return 0;
}