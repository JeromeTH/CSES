#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int n, a[SIZE], dep[SIZE], fa[SIZE][50], q;
vector<int> g[SIZE];
void dfs(int k, int lv){
    dep[k] = lv;
    for(int i =1; i <= 22; i++){
        fa[k][i] = fa[fa[k][i - 1]][i - 1];
    }
    for(auto i: g[k]){
        dfs(i, lv+1);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int k; cin >> k;
        fa[i][0] = k;
        g[k].push_back(i);
    }
    fa[1][0] = 1;
    dfs(1, 0);
    while(q--){
        int a, b;
        cin >> a >> b;
        if(dep[a] < b){
            cout << "-1\n";
        }else{
            int cur = a;
            for(int i = 22; i >= 0; i--){
                if(b & (1 << i)){
                    cur = fa[cur][i];
                }
            }
            cout << cur << endl;
        }
    }
}