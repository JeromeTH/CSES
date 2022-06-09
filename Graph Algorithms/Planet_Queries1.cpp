#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 2e5 + 5;
int n, t[SIZE], f[SIZE][40], q;
int main(){
    ios_base::sync_with_stdio (false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> f[i][0];
    }
    for(int j = 1; j < 30; j++){
        for(int i = 1; i <= n; i++){
            f[i][j] = f[f[i][j -1]][j -1];
        }
    }
    while(q--){
        int k, x;
        cin >> x >> k;
        for(int i= 0; i < 30; i++){
            if(k & (1 << i)) x = f[x][i];
        }
        cout << x << endl;
    }
}