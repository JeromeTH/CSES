#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10][10];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool avai(int x, int y){
    return (x >=1 && x <= 8 && y >=1 && y <= 8);
}
bool dfs(int x, int y, int step){
    if(step == 64){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!avai(nx, ny))continue;
        if(a[nx][ny]) continue;
        a[nx][ny] = step + 1;
        if(dfs(nx, ny, step + 1))return;
        a[nx][ny] = 0;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
    dfs(x, y);
    return 0;
}