#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define sz(x) ((int)x.size())// size susceptible to bugs because of unsigned int 
// for example -1 <= (unsigned int)0 when -1 is converted into unsigned int it becomes 
using namespace std;// #define has to have parathesese 

typedef long long ll ;// typedef is better than #define when you want to abbreviate data structure size
ll n;
int a[100001], b[100001];

int main()
{
    scanf("%lld", &n);
    int sum = (n * (n + 1))/ 2;
    if(sum% 2 != 0){
        printf("NO");
        return 0;

    }
    printf("YES\n");
    int k = sum/2;
    for(int i = 1; i <= n; i++){
        b[i] = 1;
    }
    
    for (int i = n; i >=1; i--){
        if (k == 0) break;
        if (k >= i){
            a[i] = 1, b[i] = 0;
            k -= i;
        }
    }
    int counta = 0;

    for(int i = 1; i <= n; i++){
        if (a[i] != 0) counta ++;
    }
    printf("%d\n", counta);
    for (int i = 1; i <= n; i++){
        if (a[i]== 1) printf("%d ", i);
    }
    printf("\n");
    int countb = 0;
    for(int i = 1; i <= n; i++){
        if (b[i] != 0) countb ++;
    }
    printf("%d\n", countb);
    for (int i = 1; i <= n; i++){
        if (b[i]== 1) printf("%d ",i);
    }

    return 0;

    

}