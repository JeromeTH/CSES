#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int SIZE = 2e5 + 5;
int n, a[SIZE];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int ans = 0;
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if (a[i] < a[i - 1]){
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}