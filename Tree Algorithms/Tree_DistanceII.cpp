#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int n;
const int SIZE = 2e5 + 5;
int in[SIZE], sub[SIZE], out[SIZE], fa[SIZE], vis[SIZE];
vector<int> g[SIZE];
vector<int> child[SIZE];
void dfs(int k){
    vis[k] = 1;
    //out[k] += out[fa[k]] + (n - sub[fa[k]] + 1);
    int tmp =0;
    for(auto i: g[k]){
        if(!vis[i]){
            child[k].push_back(i);
            fa[i] = k;
            dfs(i);
            sub[k] += sub[i];
            in[k] += in[i] + sub[i];
            tmp += in[i] + sub[i]*2;
        }
    }
    for(auto i: child[k]){
        out[i] += tmp;
    }
    // sibling operation is conducted at the father node, since node 1 does not have father node
    // reverse sibling operation is not required
    sub[k] ++;
    //if(k != 1) out[k] -= (in[k] + sub[k] * 2);
}
// when i is operating, fa[i] hasn't finished
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        out[i] += out[fa[i]] + n - (sub[fa[i]]) + 1;
        out[i] -= in[i] + sub[i] * 2;
    }
    //for(int i = 1; i <= n; i++) cout << fa[i] << " ";
    //cout << endl;
    for(int i = 1; i <= n; i++){
        cout << in[i] +out[i] << " ";
    }
    cout << endl;    
}