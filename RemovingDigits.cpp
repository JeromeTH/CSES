#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
const int SIZE = 1e6 + 1;
const int INF = 1e6 + 1;
ll n, dp[SIZE];
int main()
{
    scanf("%lld", &n);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++){
        ll temp = i;
        dp[i] = INF;
        while (temp){
            //printf("pre = %d\n", dp[i]);
            dp[i] = min(dp[i], dp[i - (temp%10)] + 1);
            //printf("dp = %d\n", dp[i]);
            temp /= 10;
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}