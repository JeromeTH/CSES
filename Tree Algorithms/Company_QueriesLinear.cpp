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
        if(dep[a] < b){
            cout << "-1\n";
        }else{
            int d = dep[a] - b;
            while(dep[a] > d){
                if(dep[jump[a]] > d) a = jump[a];
                else a = fa[a];
            }
            cout << a << endl;
        }
    }
}