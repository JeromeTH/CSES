#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
int n;
 
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        if(i == 1) printf("0\n");
        if(i == 2) printf("6\n");
        if (i >= 3) printf("%lld\n", ((i*i) * (i * i - 1))/2 - (i - 1)*(i - 2) * 2 * 2);
    }
    return 0;
}
