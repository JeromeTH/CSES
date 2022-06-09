#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
int n, x;
int w[50];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 0 ;i < n; i++){
        cin >> w[i];
    }
    int ans = 0;
    sort(w, w + n, greater<int> ());
    for(int i = 0; i < n; i++){
        if(w[i] == 0) continue;
        int cur = w[i];
        w[i] = 0;
        for(int j = i + 1; j < n; j++){
            if(cur+ w[j] <= x){
                cur += w[j];
                w[j] = 0;
            }
        }
        ans ++;
    }
    cout << ans << endl;
    return 0;
}