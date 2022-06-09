#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdbool>
using namespace std;
typedef long long ll;
const int SIZE = 1001;
struct dat
{
    ll index;
    ll value;
}s[SIZE];
bool cmp(dat &x, dat &y)
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
    int a, b, c, d;
    for (a = 0; a < n - 3; a++){
        for (b = a + 1; b < n - 2; b++){
            c = b + 1, d = n - 1;
            ll target =  m - s[a].value - s[b].value;
            while (d > c){
                if (s[d].value + s[c].value == target){
                    printf("%lld %lld% lld% lld\n", s[a].index + 1, s[b].index + 1, s[c].index + 1, s[d].index +1);
                    return 0;
                }
                else if(s[d].value + s[c].value > target){
                    d --;
                }
                else{
                    c ++;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    
    /*for (int i = 0; i < n; i++){
        printf("%lld\n", s[i].value);
    }
    */
    return 0;

}