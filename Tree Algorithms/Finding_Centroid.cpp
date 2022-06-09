#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int n, a[SIZE], vis[SIZE], num[SIZE], ans;
vector<int> g[SIZE];
void dfs(int k){
    vis[k] = 1;
    int ma =0;
    for(auto i: g[k]){
        if(vis[i]) continue;
        dfs(i);
        ma = max(ma, num[i]);
        num[k] += num[i];
    }
    num[k] += 1;
    if(ma <= n/2 && n - num[k] <= n/2){
        ans = k;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    /*for(int i =1; i <= n; i++){
        cout << num[i] << " ";
    }
    cout << endl;*/
    cout << ans << endl;
    return 0;
}