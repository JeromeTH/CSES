#include <iostream>// binary search a BIT
#include <cstdio>
#include <algorithm>
#include <vector> 
using namespace std;
const int SIZE = 2e5 +5;
int d, s[SIZE], n, a[SIZE], t[SIZE];
struct Fenwick{
    int p(int x){
        return x & (-x);
    }
    int get(int x){
        int res =0 ;
        while(x){
            res += t[x];
            x -= p(x);
        }
        return res;
    }
    void add(int x, int y){
        while(x < n+1){
            t[x] += y;
            x += p(x);
        }
    }
}f;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        int l =0, r = n;
        while(l < r){
            int mm = l + (r - l)/2;
            if (mm - f.get(mm) < p){
                l = mm + 1;
            }else{
                r = mm;
            }
        }
        cout << a[l] << " ";
        f.add(l, 1);
    }
    cout << endl;
    return 0;
}