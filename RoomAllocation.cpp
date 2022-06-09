#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdbool>
typedef long long ll;
using namespace std;
const int SIZE = 1e5 + 1e5 + 1;
const int MODE = 1e9 + 1;
ll n;
ll s[MODE][2] = {0};
ll location[MODE];
ll count = 0, flag;
bool cmp(ll a[], ll b[])
{
    return a[1] < b[1];
}
int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld%lld\n", &s[i][0], &s[i][1]);
    }
    ll temp[MODE][2] = s;// s will be seen as a pointer
    sort(temp, temp + n; cmp);
    for (int i = 0; i < n; i++){
        printf("%lld%lld\n", temp[i][0], temp[i][1]);
    }
    flag = n;
    /*while (flag > 0){
        for (int i = 0; i < n; i++){
            if (location[i] != 0){continue;}
            count ++;

        }
    }
    here are my thoughts about this problem
    while there are still customers in the list, increase the room number by 1, and then 
    eliminate all the customers that can use this room
    */
    
}