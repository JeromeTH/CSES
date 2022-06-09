#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n;
signed main(){
    cin >> n;
    int t =0;
    for(int cur = 2, cnt = 1; cur <= n; cur <<= 1, cnt++){
        t += cnt * (n/cur - n/(cur*2));
    }
    int f = 0;
    for(int cur = 5, cnt= 1; cur <= n; cur *= 5, cnt++){
        f += cnt * (n/cur - n/(cur*5));
    }
    cout << min(t, f) << endl;
    return 0;
}