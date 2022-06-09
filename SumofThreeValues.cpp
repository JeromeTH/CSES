#include <iostream>// how would
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n, k;
struct value{
    ll index;
    ll num;

}s[5001];
bool cmp(value &a, value &b)
{
    return(a.num <= b.num);
}
int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i].num);
        s[i].index = i + 1;
    }
    sort(s, s + n, cmp);
    int a, b, c;
    for (a = 0; a < n - 2; a++){
        b = a + 1, c = n - 1;
        while (c > b){
            if (s[a].num + s[b].num + s[c].num == k){
                printf("%lld %lld %lld\n", s[a].index, s[b].index, s[c].index);
                return 0;
            }
            else if(s[a].num + s[b].num + s[c].num > k){c--;}
            else{b++;}
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}