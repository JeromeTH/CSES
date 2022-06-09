#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const int SIZE = 2e5 + 1;
ll s[SIZE], presum[SIZE];
int main()
{
    ll n;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }
    ll res = s[0];
    presum[0] = s[0];
    for (int i = 1; i < n; i++){
        presum[i] = max(s[i], presum[i - 1] + s[i]);
        if (presum[i] > res){res = presum[i];}
    }
    printf("%lld\n", res);
    return 0;
}