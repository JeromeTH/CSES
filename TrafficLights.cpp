#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 2e5 + 1;
ll s[SIZE];
int main()
{
    ll m, n;
    scanf("%lld%lld",&m, &n);
    ll l = 0, r = m;
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
        if (s[i] >= r || s[i] <= l){
            printf("%lld ", r - l);
            continue;
        }
        if (l < s[i] && r > s[i]){
            max(r - s[i], s[i] - l)

        }
        
    }
    


}