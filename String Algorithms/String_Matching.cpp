#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int P = 401, M = 1e9 + 7;
const int SIZE = 1e6 + 5;
int h[SIZE], n, expm[SIZE];
int calc(string s, int save){
    int val = 0;
    for(int i =0; i < (int) s.size(); i++){
        val = ((val * P)%M + s[i])%M;
        if(save){
            h[i] = val;
        }
    }
    return val;
}
int sub(int l, int r){
    if(l == 0){
        return h[r];
    }
    return (h[r] - h[l - 1] * expm[r- l + 1]%M + M) %M;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    expm[0] = 1;
    for(int i = 1; i < SIZE; i++){
        expm[i] = expm[i -1] * P %M;
    }
    string S;
    cin >> S;
    calc(S, 1);
    string t;
    cin >> t;
    int v = calc(t, 0);
    int cnt = 0;
    for(int i = t.size() - 1; i < S.size(); i++){
        if(sub(i - t.size() + 1, i) == v) cnt ++;
    }
    cout << cnt << endl;
}