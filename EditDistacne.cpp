#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int SIZE = 5001;
int m, n;
int dp(int a, int b)
{
    if (a == n && b== m ) return 0;
    if (a == n){
        return m - b;
    }
    if (b ==m) return n - a;
    return min(dp(a +1, b + 1), min(dp(a + 1, b), dp(a, b + 1))) + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    getline(cin, s);
    getline (cin, p);
    n = s.length(), m = p.length();
    cout << dp(0, 0) << endl;
    return 0; 

}