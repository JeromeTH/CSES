#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int M= 1e9 + 7;
const int SIZE = 1e6 + 5;
int f1[SIZE], f2[SIZE], iv[SIZE];
int C(int a, int b){
    return f1[a] * f2[b]%M * f2[a - b]%M;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    f1[0] = f2[0] = 1;
    iv[1] = 1;
    for(int i = 2; i < SIZE; i++){
        iv[i] = M - M/i * iv[M%i] %M;
    }
    /*for(int i = 2; i <= 10; i++){
        cout << i * iv[i] % M;
    }
    cout << endl;*/
    for(int i = 1; i < SIZE; i++){
        f1[i] = f1[i -1] * i % M;
    }
    for(int i  =1; i < SIZE; i++){
        f2[i] = f2[i - 1] * iv[i] %M;
    }
    int n;
    cin >> n;
    if(n % 2){
        cout << "0\n";
        return 0;
    }
    cout << (C(n, n/2) - C(n, n/2 + 1) + M)%M << endl;
    return 0;
}