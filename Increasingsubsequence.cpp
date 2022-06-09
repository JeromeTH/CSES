#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE = 2e5 + 1;
ll dp[SIZE], s[SIZE];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        dp[i] = 1;
    }
    ll l = 0, r = 1, res = 1;
    for (r = 1; r < n; r++){
        l = 0;
        while (l < r){
            if(s[r] > s[l]){
                dp[r] = max(dp[r], dp[l] + 1);
                res = max(dp[r], res);
            }
            l++;
        }
    }
    cout << res << endl;
    return 0;

}