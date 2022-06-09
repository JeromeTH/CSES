#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1e6 + 1;
#define int long long
bool used[SIZE];
signed main(){
    int n;
    cin >> n;
    int t = n * (n + 1)/4;
    if (n * (n + 1) % 4 != 0){
        cout << "NO" << endl;
        return 0;
    }
    int cnt=  0;
    for(int i = n; i > 0; i--){
        if (t > 0 && i <= t){
            t -= i;
            used[i] = 1;
            cnt ++;
        }
    }
    if (t != 0){
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
    }
    cout << cnt << endl;
    for(int i = 1; i <=n; i++){
        if(used[i]) cout << i << " ";
    }
    cout << endl << n - cnt << endl;
    for(int i = 1; i <= n; i++){
        if (!used[i])cout << i << " ";
    }
    cout << endl;
    return 0;
}