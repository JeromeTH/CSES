#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector> 
using namespace std;
const int SIZE = 2e5 +5;
int d, s[SIZE], n, a[SIZE];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ;i++){
        cin >> a[i];
    }
    for(int i =0 ; i < n; i++){
        int p;
        cin >> p;
        int cur = p;
        cur += s[cur];
        while(s[cur + s[cur]] - s[cur] > 0){
            cur += s[cur + s[cur]] - s[cur];
        }
        cout << a[cur] << " ";
        s[cur] ++;
    }
    cout << endl;
    return 0;
}