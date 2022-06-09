#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int SIZE = 500;
const int MODE = 1e9 + 7;
typedef long long ll;
/*void read(ll matrix[][2], ll n, ll m)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll k = 0; k < m; k++)
        {
            scanf("%lld", &matrix[i][k]);
        }
    }
}
*/
void multiply(ll a[][2])
{
    ll C[SIZE][SIZE];
    ll b[SIZE][SIZE] = {{0, 1}, {1, 1}};
    for (ll i = 0; i < 2; i++)
    {
        for (ll k = 0; k < 1; k++)
        {
            for (ll j = 0; j < 2; j++)
            { //
                C[i][k] += b[i][j] * a[j][k];
                C[i][k] %= MODE;
            }
        }
    }
    for (ll i = 0; i < 2; i++)
    {
        a[i][0] = C[i][0];
    }
    
}
 
int main()
{
    ll A[3][2] = {{0}, {1}};
    
    
    ll n;
    scanf("%lld", &n);
    if(n == 0){
        printf("0");
        return 0;
    }
    for(ll i = 0; i < (n + 1)/2; i++){
        multiply(A);
    }
    if(n % 2== 0){
        printf("%lld\n", A[1][0]);
    }
    else{
        printf("%lld\n", A[0][0]);
    }
 
    return 0;
}
