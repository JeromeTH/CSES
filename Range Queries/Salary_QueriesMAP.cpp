#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
#define int long long
unordered_map<int, int> t;
const int SIZE = 2e5 + 5;
int n, q, p[SIZE];
struct BIT{
    int p(int x){
        return x & (-x);
    }
    int bit_num;
    void init(int n){
        while(n >> bit_num) bit_num ++;
    }
    void add(int x, int y){
        while(!(x >> bit_num)){
            t[x] += y;
            x += p(x);
        }
    }
    int get(int x){
        int res = 0;
        while(x){
            res += t[x];
            x -= p(x);
        }
        return res;
    }
}f;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    f.init(1e9 + 1);
    for(int i= 1; i <= n; i++){
        cin >> p[i];
        f.add(p[i], 1);
    }
    while(q--){
        char ty; cin >> ty;
        if(ty == '?'){
            int a, b;
            cin >> a >> b;
            cout << f.get(b) - f.get(a -1) << endl;
        }else{
            int k, x;
            cin >> k >> x;
            f.add(p[k], -1);
            f.add(x, 1);
            p[k] = x;
        }
    }
    return 0;
}