#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int n;
const int SIZE = 2e5 + 5;
struct point{
    int x, y;
}p[SIZE], ch[SIZE];
double cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool compare(point a, point b){
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
int Monotone_Chain(){
    sort(p, p + n, compare);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross(ch[m -2], ch[m - 1], p[i]) < 0) m--;
        ch[m++] = p[i];
    }
    for(int i = n - 2, t = m + 1; i >= 0; i--){
        while(m > t && cross(ch[m - 2], ch[m - 1], p[i]) < 0) m--;
        ch[m++] = p[i];
    }
    m--;
    return m;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    int out = Monotone_Chain();
    //cout << out << " " << n - out << endl;
    return 0;
}