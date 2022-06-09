#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int SIZE = 101;
const int C = 1e6 + 1;
#define INF 1e8;
ll n, c[101], dp[C];
ll find(ll x)
{
    ll r = INF;
    for (int i = 0; i < n; i++){
        if (x == c[i]){
            //printf("return 1ed\n");
            return 1;
        }
        if (x - c[i] > 0){
            if (dp[x - c[i]] == -1){dp[x - c[i]] = find(x - c[i]);}
            r = min(r, dp[x - c[i]]);
        }
    }
    return r + 1;
}
int main()
{
    ll k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%lld", &c[i]);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = find(k);
    if (ans > 100000000){
        printf("-1");
        return 0;
    }
    printf("%lld\n", ans);
    return 0;  
}