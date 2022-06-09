#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll s[105];
int main()
{
    int tc;
    cin >> tc;
    while (tc--){
        int n, k;
        ll sum = 0, res = 0, ans = 0;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            sum += s[i];
        }
        for (int i = n -1; i >= 1; i--){
            sum -= s[i];
            if (s[i] * 100 <= sum * k) continue;
            if (s[i] * 100 % k != 0)res = s[i] * 100/k + 1 - sum;// 
            else res = s[i] * 100 / k - sum;
            sum += res;
            ans += res;
        }
        cout << ans << endl;
    }
    return 0;
}