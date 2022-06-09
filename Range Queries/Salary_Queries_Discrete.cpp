#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int SIZE = 1e6 + 5;
int n, q, p[SIZE], t[SIZE];
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
map<int, int> dis;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    f.init(200005);
    vector<int> op;
    for(int i= 1; i <= n; i++){
        cin >> p[i];
        op.push_back(p[i]);
    }
    vector<pair<int, int> >query;
    vector<pair<int, int> >upd;
    string s;
    for(int i = 0; i < q; i++){
        char ty; cin >> ty;
        s += ty;
        if(ty == '?'){
            int a, b;
            cin >> a >> b;
            op.push_back(a);
            op.push_back(b);
            query.push_back({a, b});
        }else{
            int k, x;
            cin >> k >> x;
            op.push_back(x);
            upd.push_back({k, x});
        }
    }
    vector<int> b(op.size());
    for(int i = 0; i < op.size(); i++){
        b[i] = op[i];
    }
    sort(b.begin(), b.end());
    /*for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;*/
    int m = unique(b.begin(), b.end()) - b.begin();
    /*for(auto i = b.begin(); i != b.begin() + m; i++){
        cout << *i << " ";
    }
    cout << endl;*/
    for(int i = 0; i < op.size(); i++){
        int d = lower_bound(b.begin(), b.begin() + m, op[i]) - b.begin() + 1;
        dis[op[i]] = d;
    }
    for(int i = 1; i <= n; i++){
        p[i] = dis[p[i]];
        f.add(p[i], 1);
    }
    int l = 0, r = 0;
    for(int i = 0; i < q; i++){
        if(s[i] == '?'){
            int a = dis[query[l].first];
            int b = dis[query[l].second];
            cout << f.get(b) - f.get(a - 1) << endl;
        }else{
            int k= upd[r].first;
            int x = dis[upd[r].second];
            f.add(p[k], -1);
            f.add(x, 1);
        }
    }
    
    return 0;
}
/*
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
*/