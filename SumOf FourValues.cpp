#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdbool>
using namespace std;
typedef long long ll;
const int SIZE = 1001;
struct data
{
    ll index;
    ll value;
}s[SIZE];
bool cmp(data &x, data &y)
{
    return (x.value < y.value);
}
int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i].value);
        s[i].index = i;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++){
        printf("%lld\n", s[i].value);
    }

}