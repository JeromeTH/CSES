#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pii pair<int, int> 
const int SIZE = 1e6;
const int M = 1e9 + 7;
int n, a[SIZE], b[SIZE], q;
Tree<pii> o;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i  =1; i <= n; i++){
        cin >> a[i];
        o.insert({a[i], i});
    }
    while(q--){
        char c;
        cin >> c;
        if(c == '!'){
            int x, y;
            cin >> x >> y;
            o.erase({a[x],x});
            a[x] = y;
            o.insert({a[x], x});
        }else{
            int x, y;
            cin >> x >> y;
            cout << o.order_of_key({y, M}) - o.order_of_key({x -1, M}) << "\n";
        }
    }
}
/*
cd "/Users/jerome/CSES/Range Queries/" && gcc Salary_Queries_Indexedset.cpp -std=c++17-o Salary_Queries_Indexedset && "/Users/jerome/CSES/Range Queries/"Salary_Queries_Indexedset
cd "/Users/jerome/CSES/Range Queries/" && gcc Salary_Queries_Indexedset.cpp -std=c++17 -o Salary_Queries_Indexedset && "/Users/jerome/CSES/Range Queries/"Salary_Queries_Indexedset