#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int SIZE = 2e5 + 5;
int n;
struct point{
    int x, y;
}P[SIZE], CH[SIZE];
double cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare(point a, point b){
    return (a.x < b.x)||(a.x == b.x && a.y < b.y);
}

int Monotone_Chain(){
    sort(P, P + n, compare);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross(CH[m - 2], CH[m - 1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    for(int i = n - 2, t = m + 1; i >= 0; i--){
        while(m >= t && cross(CH[m -2], CH[m - 1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    m--;
    return m;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i  =0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }
    int ans= Monotone_Chain();
    cout << ans << endl;
    for(int i = 0; i < ans; i++){
        cout << CH[i].x << " " << CH[i].y << endl;
    }
    return 0;
}