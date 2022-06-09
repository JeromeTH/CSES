#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
#define pii pair<int, int> 
using namespace std;
const int SIZE = 2e5 + 5;
int n, scc[SIZE], m, cnt, num[SIZE], t[SIZE], ans, timer, low[SIZE], dfn[SIZE], vis[SIZE], dp[SIZE], vis2[SIZE];
vector<int> g[SIZE], gscc[SIZE];
vector<int> stk;
void dfs(int u){
    dfn[u] = low[u] = ++timer;
    vis[u] = 1;
    stk.push_back(u);
    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        cnt ++;
        int tt;
        do{
            tt = stk.back();
            stk.pop_back();
            scc[tt] = cnt;
        }while(tt != u);
    }
}
int dfs2(int u){
    if(vis2[u]) return dp[u];
    vis2[u] = 1;
    for(auto v: gscc[u]){
        dp[u] = max(dp[u], dfs2(v));
    }
    dp[u] += num[u];
    return dp[u];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    /*for(int i = 1; i <= n; i++){
        cout << scc[i] << " ";
    }
    cout << endl;*/
    for(int i = 1; i <= n; i++){
        num[scc[i]] += t[i];
        for(auto j: g[i]){
            if(scc[i] == scc[j])continue;
            gscc[scc[i]].push_back(scc[j]);
        }
    }
    for(int i =1; i <= cnt; i++){
        sort(gscc[i].begin(), gscc[i].end());
        int mm = unique(gscc[i].begin(), gscc[i].end()) - gscc[i].begin();
        for(int j = gscc[i].size() - 1; j >= mm; j--) gscc[i].pop_back();
        //cout << "scc" << i << endl;
        //cout << mm << endl;
        //for(auto j: gscc[i]) cout << j << " ";
        //cout << endl;
        //cout << num[i] << " ";
        if(dp[i] == 0) dfs2(i);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}