#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 1000;
struct point{
    int x, y;
}P[SIZE], CH[SIZE];
int n;
int cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare_position(point a, point b){
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

int length2(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool compare_angle(point a, point b){

    int c = cross(P[0], a, b);
    return c > 0 || (c == 0 && length2(P[0], a) < length2(P[0], b));
}
int Graham_Scan(){
    swap(P[0], *min_element(P, P + n, compare_position));

    sort(P + 1, P + n, compare_angle);
    P[n] = P[0];

    int m = 0;
    for(int i = 0; i <= n; i++){
        while(m >= 2 && cross(CH[m - 2], CH[m -1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    m--;
    return m;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }
    int ans = Graham_Scan();
    cout << ans << endl;
    for(int i = 0; i < ans; i++){
        cout << CH[i].x << " " << CH[i].y << endl;
    }
    return 0;
}

