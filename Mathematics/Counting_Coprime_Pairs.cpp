#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
// f[i] the # of pair (a, b) with i | gcd(a, b)
// g[i] # if pairs(a, b) with gcd(a, b) = i;
// g[i] = f[i] - g[2*i] - g[3*i]...
const int SIZE = 1e6 + 5;
int sieve[SIZE];
int n, x[SIZE], cnt[SIZE], f[SIZE], g[SIZE];
void seive(){
    vector<int> primes;
    for(int i = 2; i <= n; i++){
        if(!sieve[i]) primes.push_back(i);
        for(int j = i*i; j <= n; j += i){
            sieve[i] = 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int ma = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        cnt[x[i]] ++;
        ma = max(ma, x[i]);
    }
    for(int i = 2; i <= ma; i++){
        int now = 0;
        for(int j = i; j <= ma; j += i){
            now += cnt[j];
        }
        f[i] = now*(now -1)/2;
        //cout << f[i] << " ";
    }
    //cout << endl;
    int ans = 0;
    for(int i = ma; i >= 2; i--){
        g[i] = f[i];
        for(int j = 2*i; j <= ma; j+=i){
            g[i] -= g[j];
        }
        ans += g[i];
    }
    cout << n*(n -1 )/2 - ans << endl;
    return 0;
}