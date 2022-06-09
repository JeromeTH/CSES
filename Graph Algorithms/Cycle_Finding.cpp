#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int n, m;
const int SIZE = 1e6 + 5;
const int INF = 1e18;
int dis[SIZE], p[SIZE];
struct edge{
    int a, b, cost;
}e[SIZE];
vector<int> g[SIZE];
void solve(){
    int x;
    for(int i = 0; i < n ;i++){
        x = -1;
        for(int j = 0; j < m; j++){
            if(dis[e[j].b] > dis[e[j].a]+ e[j].cost){
                dis[e[j].b] = max(-INF, dis[e[j].a] + e[j].cost);
                p[e[j].b] = e[j].a;
                x = e[j].b;
            }
        }
    }
    if(x == -1){
        cout << "NO\n";
        return;
    }
    int y = x;
    for(int i = 0; i < n; i++){
        y = p[y];
    }
    vector<int> path;
    for(int cur = y; ; cur = p[cur]){
        path.push_back(cur);
        if(cur == y && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n";
    for(auto j: path) cout << j << " ";
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i =0; i < m ;i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    solve();
    return 0;
}