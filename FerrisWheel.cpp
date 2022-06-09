#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdbool>
#include <cstring>
using namespace std;
typedef long long ll;
const int SIZE = 1e5 + 1e5 + 1;
ll n, w, s[SIZE];
int main()
{
    scanf ("%lld%lld", &n, &w);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }
    sort(s, s + n);
    ll count = 0, index = n - 1, start = 0;
    while(index >= start){
        if (index == start){
            count ++;
            break;
        }
        if (s[index] + s[start] <= w){
            count ++, index --, start ++;
            //printf("double\n");
        }
        else{
            count ++;
            index --;
            //printf("single\n");
        }
    }
    printf("%lld\n", count );
    return 0;
    
}