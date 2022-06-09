#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int size = 1e9 + 1;
ll n, s[200001], t[200001];
int exist[200001];
int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
        t[i] = s[i];
    }
    sort(t, t + n);
    for (int i = 0; i < n; i++){
        ll rr = n - 1, ss = 0, mid = (n - 1)/2;
        printf("Processing s[%d]\n", i);
        while (rr > ss){
            mid = (rr + ss)/2;
            if (t[mid] < s[i]){
                //printf("%lld\n", t[mid]);
                ss = mid + 1;
            }
            else{rr = mid;}
        }
        s[i] = rr;
        printf("s[%d] = %lld\n", i, rr);
    }
    /*for (int i = 0; i < n; i++){
        ll rr = n - 1, ss = 0, mid = (n - 1) / 2;
        while(rr - ss > 0){
            if (t[mid] == s[i]){
                s[i] = mid;
                //printf("s[%d] = %lld\n", i, mid);
                break;
            }
            else if (t[mid] > s[i]){
                rr = mid;
                mid = (rr + ss) / 2;
            }
            else{
                ss = mid;
                mid = (rr + ss + 1) / 2;
            }
        }
        

    }
    */
    /*for (int i = 0; i < n; i++){
        printf("%lld\n", s[i]);
    }
    */
    ll a = 0, b = 0, res = 0;
    for (b = 0; b < n; b++){
        exist[s[b]] ++;
        while (exist[s[b]] > 1){
            exist[s[a]] --;
            a ++;
        }
        res = max(b - a + 1, res);
        
    }
    printf("%lld\n", res);
    return 0;
    
}