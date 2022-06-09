#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
#include <algorithm>
#include <cstdbool>

using namespace std;
const int SIZE = 1e5 + 1e5 + 1;
struct movie{
    ll start;
    ll end;
}a[SIZE];
bool cmp(const movie &x, const movie &y)
{
    return x.end < y.end;
}
int main()
{
    ll n;
    

    scanf ("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf ("%lld%lld", &a[i].start, &a[i].end);
    }
    sort (a, a+n, cmp);
    ll en = a[0].end ;
    ll count = 1;
    for (int i = 0; i < n; i ++){
        if(a[i].start >= en){
            count ++;
            en = a[i].end;
        }
    }
    /*for (int i = 0; i < n; i++){
        printf("r%lld %lld\n", a[i].start, a[i].end);
    }
    */
    
    printf("%lld\n", count);
    
    
    return 0;
}