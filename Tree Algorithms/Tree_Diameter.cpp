#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int n;
vector<int> g[SIZE];
int c[SIZE], dep[SIZE], ans, used[SIZE], ma[SIZE];
void dfs(int k){
    used[k] = 1;
    priority_queue<int> p;
    for(auto i: g[k]){
        if(!used[i]){
            dfs(i);
            ma[k] = max(ma[k], ma[i] + 1);
            p.push(ma[i] + 1);
        }
    }
    int d1 = 0, d2= 0;
    if(!p.empty()){
        d1= p.top();
        p.pop();
    }
    if(!p.empty()){
        d2 = p.top();
        p.pop();
    }
    ans = max(ans, d1+d2);
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
    dep[1] = 0;
    dfs(1);
    cout << ans << endl;
}