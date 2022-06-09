#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int SIZE = 2e5 +5;
int n, a[SIZE], b[SIZE], cnt[SIZE];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i =0 ; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    for(int i =0 ; i < n; i++){
        a[i] = lower_bound(b, b + m, a[i]) - b +1;
        //cout << a[i] << " ";
    }
    int l = 0, r = 0, ans =0;
    for(r = 0; r < n; r++){
        cnt[a[r]]++;
        while(cnt[a[r]] > 1){
            cnt[a[l++]]--;
        }
        ans = max(ans, r - l+ 1);
    }
    cout << ans << endl;
    return 0;
}