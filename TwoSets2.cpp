#include <iostream>// problem with MODEs

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
#define vll vector<ll>
const int M = 1e9 + 7;
using namespace std;
int main()
{
    ll n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2){
        cout << "0\n";
        return 0;
    }
    ll k = (n * (n + 1))/2;
    vector<vll> dp(n + 1, vll(k));// how many ways to sum up k using integers 1 to n.
    for (int i = 0; i <=n; i++)dp[i][0] = 1;
    //dp[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int k = 1; k <= (i * (i + 1))/2; k++){
            dp[i][k] = dp[i - 1][k]%M;
            if (k - i >= 0) {
                dp[i][k]  = (dp[i][k] + (dp[i -1][k - i])%M)%M;
                //dp[i][k] %= M;
            }
        }
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    ll iv2 = M - M/2;
    cout << (dp[n][k/2]*iv2)%M << endl;
    //cout << k << endl;
    return 0;
}