#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int SIZE=  2e5 + 5;
const int INF = 1e18;
const int M = 1e9 + 7;
vector<int> g[SIZE];
int n, m, dp[SIZE], vis[SIZE];
int dfs(int u){
    if(vis[u]) return dp[u];
    vis[u] =1;
    for(auto v: g[u]){
        dp[u] += dfs(v);
        if(dp[u] >= M) dp[u] -= M;
    }
    return dp[u];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vis[n] = 1;
    dp[n] = 1;
    cout << dfs(1) << endl;
    return 0; 
}
