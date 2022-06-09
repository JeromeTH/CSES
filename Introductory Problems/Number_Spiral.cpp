#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int x, y;
int solve(int x, int y){
    int res =0 ;
    if (y > x){
        if (y % 2 == 0){
            res = (y - 1) * (y - 1) + 1;
            res += (x - 1);
        }else{
            res = y * y;
            res -= (x - 1);
        }
    }else{
        if (x % 2 == 0){
            res = x * x;
            res -= (y - 1);
        }else{
            res = (x - 1) * (x - 1) + 1;
            res += (y - 1);
        }
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;

}
