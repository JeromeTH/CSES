#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
long long int find(long long int a, long long int b)
{
    int n = 0;
    while(n < max(a , b) - 1){
        n++;
    }
    int count = n * n;
    if (n % 2 == 0){
        if (a >= b) count += b;
        else count = (n + 1)*(n + 1) - a + 1;
        
    }
    else{
        if (b >= a) count += a;
        else count = (n + 1)*(n + 1) - b + 1;
    }
    return count;
}
long long int s[100001][2];
long long int t;
int main()

{
    scanf("%lld", &t);
    for(int i = 0; i < t; i++){
        scanf("%lld %lld", &s[i][0], &s[i][1]);

        

    }
    for(int i = 0; i < t; i++){
        printf("%lld\n", find(s[i][0], s[i][1]));
    }
    return 0;


}