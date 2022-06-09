#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int cur = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n ;i++){
            int x; cin >> x;
            cur ^= x;
        }
        if(cur != 0) cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}