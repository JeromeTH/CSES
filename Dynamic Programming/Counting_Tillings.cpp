#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring> 
#define int long long
using namespace std;
int n, m;
const int SIZE = 1500;
const int M = 1e9 + 7;
int dp[SIZE][1 << 11];
void generate_next_mask(int cur_mask, int i, int next_mask, vector<int> &next_masks){
    if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
    }
    if((cur_mask & (1 << i)) != 0){
        generate_next_mask(cur_mask, i + 1, next_mask, next_masks);
    }
    if(i != n){
        if((cur_mask & (1 << i)) == 0 && ((cur_mask & (1 << (i +1))) == 0)){
            generate_next_mask(cur_mask, i + 2, next_mask, next_masks);
        }
    }
    if((cur_mask & (1 << i)) == 0){
        generate_next_mask(cur_mask, i + 1, next_mask + (1 << i), next_masks);
    }
}
int solve(int col, int mask, const int m, const int n){
    if(col == m + 1){
        if(mask == 0) return 1;
        return 0;
    }

    if(dp[col][mask] != -1){
        return dp[col][mask];
    }

    int ans = 0;
    vector<int> next_masks;
    generate_next_mask(mask, 1, 0, next_masks);
    for(int nmask: next_masks){
        ans = ans + solve(col + 1, nmask, m, n);
        if(ans >= M) ans -= M;
    }
    return dp[col][mask] = ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, m, n) << "\n";
    return 0;
}