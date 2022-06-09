#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE = 1000;
const int MODE = 1e9 + 7;
char s[SIZE][SIZE];
ll dp[SIZE][SIZE] = {0};// s[i][j] = dp[]
int main()
{
    int n;
    scanf ("%d", &n);
    scanf("\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%c", &s[i][j]);
        }
        if (i != n - 1){scanf("\n");}
    }
    //printf("yikes = %c\n", s[0][0]);
    dp[0][0] = 1;
    if (s[n - 1][n - 1] == '*'){
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j =0; j < n; j++){
            //printf("s[%d][%d] = %c\n", i, j, s[i][j]);
            if (s[i][j] == '#'){
                continue;
            }
            if(i > 0 && s[i - 1][j] == '.'){dp[i][j] += dp[i - 1][j];}
            if(j > 0 && s[i][j - 1] == '.'){
                dp[i][j] += dp[i][j - 1];
                //printf("\n");
            }
            dp[i][j] %= MODE;
            //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
        }
    }
    printf("%lld\n", dp[n- 1][n - 1]);
    return 0;

}
