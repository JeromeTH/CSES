#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int SIZE = 1e5 + 1;
void output(vector<int> k){
    for(auto i: k){
        cout << i << " ";
    }
    cout << endl;
}
vector<int> g[SIZE];
int prv[SIZE], used[SIZE];
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    used[1] = 1;
    prv[1] = 1;
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(auto i: g[cur]){
            if (!used[i]){
                q.push(i);
                used[i] = 1;
                prv[i] = cur;
            }
        }
        if (used[n]){
            cur = n;
            vector<int> ans;
            while(prv[cur] != cur){
                ans.push_back(cur);
                cur = prv[cur];
            }
            ans.push_back(1);
            cout << ans.size() << endl;
            reverse(ans.begin(), ans.end());
            output(ans);
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}