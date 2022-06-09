#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int n, m;
const int SIZE = 1e6 + 5;
const int INF = 1e18;
int dis[SIZE], p[SIZE], neg[SIZE], vis[SIZE];
struct edge{
    int a, b, cost;
}e[SIZE];
vector<int> g[SIZE];
bool dfs(int u){
    //cout << u << endl;
    vis[u] = 1;
    if(neg[u] == 1) return true;
    for(auto j: g[u]){
        if(vis[j]) continue;
        if(dfs(j)) return true;
    }
    return false;
}
void solve(){
    int x;
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    vector<int> lp;
    for(int i = 0; i < n; i++){
        x = -1;
        lp.clear();
        for(int j = 0; j < m; j++){
            if(dis[e[j].a] >= INF) continue;
            if(dis[e[j].b] > dis[e[j].a] + e[j].cost){
                dis[e[j].b] = dis[e[j].a] + e[j].cost;
                lp.push_back(e[j].b);
                x = e[j].b;
                p[e[j].b] = e[j].a;
            }
        }
    }
   // for(int i = 1; i <= n; i++) cout << dis[i] << " ";
   // cout << endl;
   //cout << x << endl;
    if(lp.size() > 0){
        
        for(auto j: lp){
            if(neg[j]) continue;
            int y = j;
            for(int i = 0; i < n; i++){
                y = p[y];
            }
            for(int cur = y, cnt = 0; ; cur = p[cur], cnt++){
                neg[cur] = 1;
                if(cnt > 0 && cur == y) break;
            }
        }
        if(dfs(n)) cout << "-1\n";
        else cout << -dis[n] << endl;

    }
    else cout << -dis[n] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b,c ;
        cin >> a >> b >> c;
        e[i] = {a, b, -c};
        g[b].push_back(a);
    }
    solve();
    //for(int i = 1; i <= 6; i++) cout << neg[i] << " ";
    //cout << endl;
    return 0;
}