#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <vector> 
#define int long long
using namespace std;
const int MAXN = 21;
int n, k;
int a[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> a[i];
    int ans =0;
    for(int mask = 1; mask < (1 << k); mask ++){
        int now = __builtin_popcount(mask);
        int cur = 1;
        int f =0;
        for(int i = 0; i < k; i++){
            if(mask & (1 << i)){
                if( a[i] > n/cur ){
                    f = 1;
                    break;
                }
                cur *= a[i];
            }
        }
        if(f == 1) continue;
        if(now % 2 == 1){
            ans += n/cur;
        }else{
            ans -= n/cur;
        }
    }
    cout << ans << endl;
    return 0;
}