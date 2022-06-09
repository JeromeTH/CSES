#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int pos[SIZE], v[SIZE], c[SIZE];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin  >> v[i];
        pos[v[i]] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(pos[i] > pos[i + 1]){
            ans ++;
            c[i] = 1;
        }
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        int cur = 0;
        cur += c[v[a] -1] + c[v[a]] + c[v[b -1]] + c[v[b]]; 
        pos[v[a]] = b, pos[v[b]] = a;
        swap(v[a], v[b]);
        if(pos[v[a] -1] < pos[v[a]])
    }
}