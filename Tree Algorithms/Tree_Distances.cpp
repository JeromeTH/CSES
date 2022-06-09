#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
vector<int> g[SIZE];
int n, m, d[SIZE][4];
int bfs(int k, int v){
    queue<pair<int, int> >q;
    vector<int> vis(n+2);
    q.push({k, 0});
    vis[k] = 1;
    int u, lv;
    while(!q.empty()){
        u = q.front().first; lv = q.front().second;
        q.pop();
        d[u][v] = lv;
        for(auto i: g[u]){
            if(!vis[i]){
                q.push({i, lv+1});
                vis[i] = 1;
            }
        }
    }
    return u;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int d1 = bfs(1, 0);
    int d2 = bfs(d1, 1);
    int d3 = bfs(d2, 2);
    for(int i = 1; i <= n; i++){
        cout << max(d[i][1], d[i][2]) << " ";
    }
    cout << endl;
    //cout << d1 << " " << d2 << endl;
    return 0;

}