#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define int long long
#define pii pair<int, int> 
const int MAXN = 21;
pii best[1 << MAXN];
int n, x, w[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    best[0] = {1, 0};
    for(int mask = 1; mask < (1 << n); mask++){
        best[mask] = {n + 1, 0};
        for(int p = 0; p < n; p++){
            if(!(mask & (1 << p))) continue;
            auto option = best[mask ^ (1 << p)];
            if(option.second + w[p] <= x){
                option.second += w[p];
            }else{
                option.first ++;
                option.second  = w[p];
            }
            best[mask] = min(best[mask], option);
        }
    }
    cout << best[(1 << n) - 1].first << endl;
    return 0;
}