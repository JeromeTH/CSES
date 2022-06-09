#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n, t, k[200001];
ll cmp(ll x)
{
    ll count = 0;
    for (ll i = 0; i < n; i++){
        count += x/k[i];
        if (count >= 1e18){break;}
    }
    //printf("%lld, x = %d\n", count, x);
    return count;
}
int main()
{
    scanf("%lld%lld", &n, &t);
    for (ll i = 0; i < n; i++){
        scanf("%lld", &k[i]);
    }
    
    ll ri = t * k[0], le = 0, mid;
    while (ri > le){
        mid = (ri + le)/2;// = le
        if (t <= cmp(mid)){ri = mid;}
        else{le = mid + 1;}
    }
    printf("%lld\n", le);

}