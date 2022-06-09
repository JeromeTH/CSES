#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 1e5 + 5;
int n, m, scc[SIZE], cnt, low[SIZE], dfn[SIZE], timer, vis[SIZE];
vector<int> g[SIZE];
vector<int> stk;
void dfs(int u){
    low[u] = dfn[u] = ++timer;
    vis[u] = 1;
    stk.push_back(u);
    for(auto v: g[u]) {
        if(!vis[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        cnt ++;
        int t;
        do{
            t = stk.back(); stk.pop_back();
            scc[t] = cnt;
        }while(t != u);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++) cout << scc[i] << " ";
    cout << endl;
    return 0;
}