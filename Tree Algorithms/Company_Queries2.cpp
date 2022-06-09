#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int n, a[SIZE], dep[SIZE], fa[SIZE], jump[SIZE], q;
vector<int> g[SIZE];
void dfs(int k, int lv){
    dep[k] = lv;
    if(dep[jump[fa[k]]] - dep[fa[k]] == dep[jump[jump[fa[k]]]] - dep[jump[fa[k]]]) jump[k] = jump[jump[fa[k]]];
    else jump[k] = fa[k];
    for(auto i: g[k]){
        dfs(i, lv+1);
    }
}
int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    // a has a deeper depth
    while(dep[a] > dep[b]){
        if(dep[jump[a]] > dep[b]) a = jump[a];
        else a = fa[a];
    }
    while(a != b){
        if(jump[a] != jump[b]){
            a = jump[a];
            b = jump[b];
        }else{
            a = fa[a];
            b = fa[b];
        }
    }
    return a;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int k; cin >> k;
        fa[i] = k;
        g[k].push_back(i);
    }
    fa[1] = 1;
    dfs(1, 0);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}