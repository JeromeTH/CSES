#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int SIZE = 1e6 + 5;
int n, iv[SIZE];
int mul(int x, int y){
    return (x*y + M) %M;
}
int exp(int x, int y){
    int res = 1;
    int cur = x;
    while(y){
        if(y & 1) res = res * cur % M;
        cur = cur * cur % M;
        y >>= 1;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int num = 1, cur = 1;
    iv[1] = 1;
    int N = 1;
    for(int i = 2; i < SIZE; i++){
        iv[i] = M - M/i * iv[M%i]%M;
    }
    //for(int i = 1; i <= 10; i++) cout << i * iv[i] %M;
    //cout << endl;
    //cout << exp(5, 3) << endl;
    int did = 0;
    int half = 1;
    int root = -1;
    int num2 = 1;
    for(int i = 0; i < n; i++){
        int x, k; cin >> x >> k;
        N = mul(N, exp(x, k));
        num = mul(num, k +1);
        num2 = num2 * (k + 1) % (M - 1);
        cur = mul(cur, (exp(x, k + 1) - 1) * iv[x - 1] %M);
        if(did == 0 && k % 2 != 0){
            half = half * ((k + 1)/2) %(M - 1);
            did = 1;
        }else{
            half = half * (k + 1) % (M -1);
        }
        if(root == -1){
            root = mul(1, exp(x, k/2));
        }else{
            root = mul(root, exp(x, k/2));
        }
    }

    int product;
    //cout << half << endl;
    if(did){
        product = exp(N, half);
    }
    else{
        product = exp(root, num2);
    }
    cout << num << " " << cur << " " << product << endl;
    return 0;
}