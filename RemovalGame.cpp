#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll s[5001];
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        sum += s[i];
    }
    vector<vll> dp(n + 1, vll(n + 1));
    for (int l = n - 1; l >= 0; l--){
        for (int r = l; r < n; r++){
            if (r == l){
                dp[l][r] = s[r];
                continue;
            }
            dp[l][r] = max(s[l] - dp[l + 1][r], s[r] - dp[l][r - 1]);
        }
    }
    cout << (sum+dp[0][n - 1])/2 << endl;
    return 0;
}