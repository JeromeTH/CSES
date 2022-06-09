#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#define int long long
#pragma GCC optimize ("Ofast")
using namespace std;
const int SIZE = 2e5 + 5;
#define pii pair<int, int> 
set<int> g[SIZE];
int n, m;
pii e[SIZE];
vector<int> ans;
unordered_map<int, int> mp;
int get(int u, int v){
    if(v > u) swap(u, v);
    return u*(n  +5) + v;
}
void find_path(int u){
    //cout << u << endl;
    for(auto v: g[u]){
        if(mp[get(u, v)]) continue;
        mp[get(u, v)]= 1;
        find_path(v);
    }
    ans.push_back(u);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    int v1 = -1, v2 = -1;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        e[i] = {a, b};
    }
    vector<int> odd;
    for(int i = 1; i <= n; i++){
        if(g[i].size() % 2 == 1){
            odd.push_back(i);
        }
    }
    if(odd.size() > 0) cout << "IMPOSSIBLE\n";
    else if(g[1].size() == 0) cout << "IMPOSSIBLE\n";
    else{
        //ans.push_back(1);
        find_path(1);
        for(int i = 0; i < m; i++){
            if(mp[get(e[i].first, e[i].second)] == 0){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        for(auto i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}