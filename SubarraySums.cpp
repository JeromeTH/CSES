#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;
ll n, k, s[200001];
/*ll sum(ll a, ll b)
{
    assert(b >= a);
    ll res = 0;
    for (int i = a; i <= b; i++){
        res += s[i];
    }
    return res;
*/
int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }
    ll count = 0;
    ll le = 0, ri = 0, sum = s[0];
    while(ri < n){
        if (sum == k){
            //printf("le = %lld, ri = %lld\n",le,  ri);
            ri ++, sum += s[ri], sum -= s[le], count ++, le++;
            
        }
        else if(sum < k){
            //printf("else if le = %lld, ri = %lld, sum = %lld\n", le, ri, sum);
            ri ++, sum += s[ri];
        }
        else{
            //printf("else le = %lld, ri = %lld\n", le, ri);
            sum -= s[le], le++;            
        }
    }
    printf("%lld\n", count);
    return 0;

}