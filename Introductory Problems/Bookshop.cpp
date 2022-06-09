#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1050;
int n, w[SIZE], v[SIZE], dp[100005], x;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    dp[0] = 0;
    for(int i = 1; i <= n; i++)cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    int ans = 0;
    for(int i =0 ; i <= x; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}