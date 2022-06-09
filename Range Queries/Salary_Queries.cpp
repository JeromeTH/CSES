#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int p[SIZE], n, q;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    multiset<int> s;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        s.insert(p[i]);
    }
    while(q--){
        char c;int a, b;
        cin >> c >> a >> b;
        if (c == '!'){
            s.erase(s.find(p[a]));
            p[a] = b;
            s.insert(p[a]);
        }else{
            auto k = s.upper_bound(b) - s.lower_bound(a);
            cout << k << endl;
        }
    }
    return 0;
}