#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int SIZE = 2e5 + 1;
int d[SIZE], num[SIZE], p[SIZE];
vector<pair<int, int> > rd;
struct Union_find{
    void init(int n){
        for(int i = 1; i <= n; i++){
            d[i] = p[i] = i;
            num[i] = 1;
        }
    }
    int find(int x){
        while(x != d[x])x = d[x];
        return x;
    }
    void uu(int x, int y){
        x = find(x);
        y = find(y);
        if (num[x] > num[y])swap(x, y);
        d[x] = y;
        num[y] += num[x];
        num[x] = num[y];
    }
}U;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    U.init(n);
    for(int i = 0; i < m; i++){
        int a, b;cin >> a >> b;
        U.uu(a, b);
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if (U.find(i) != U.find(i - 1)){
            U.uu(i, i - 1);
            rd.push_back(make_pair(i, i -1));
            ans ++;
        }
    }
    cout << ans << endl;
    for(auto i: rd){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}