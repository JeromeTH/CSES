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
        int n; cin >> n;
        int w = 0, l = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            x %= 4;
            w ^= x;
        }
        if(w == 0) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}