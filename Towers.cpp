#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set> 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    multiset<int> m;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        if(m.upper_bound(k) == m.end()){
            m.insert(k);
        }else{
            int cur = *m.upper_bound(k);
            m.erase(m.find(cur));
            m.insert(k);
        }
    }
    cout << m.size() << endl;
    return 0;
}