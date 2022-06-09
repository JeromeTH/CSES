#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll n;
ll s[100001];
int main(){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }

    ll count = 0;
    for (ll i = 1; i < n; i++){
        if (s[i] >= s[i - 1]){continue ;}
        
        count += s[i - 1] - s[i];
        s[i] = s[i - 1];
    }
    printf("%lld", count);
    
    return 0;
}