#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue> 
#include <map> 
using namespace std;
const int SIZE = 1001;
char s[SIZE][SIZE], dis[SIZE][SIZE];// denote the distance of the closest monster
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct dat{
    pair<int , int> i;
    int d;
    dat(pair<int, int> _x = {0, 0}; int v = 0): i(_x), d(v){};
}
bool avai(int i, int j, map<pair<int, int> >vi){
    if (i<n && i >= 0 && j < m && j >= 0){
        if (vi[{i, j}] = 0)return true;
    }
    return false;
}
bool bfs(pair<int, int> i, int type){
    bool used[SIZE][SIZE];
    map<pair<int, int>> vis;
    cout << vis[{0, 0}] << endl;
    queue<dat> q;
    q.push(dat(i, 0));
    vis[i] = 1;
    while(!q.empty()){
        int lv = q.front().d;
        pair<int, int> cur = q.front().i;
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (avai(nx, ny, vis)){
                vis[{nx, ny}] = 1;
                q.push(dat({nx, ny}, lv + 1));
                if (dis[nx][ny] > lv + 1) dis[nx][ny] = lv + 1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    vector<pair<int, int> > mst;
    pair<int, int> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
            if (s[i][j] == 'M')mst.push_back({i, j});
            if (s[i][j] == 'A')st = {i, j};
        }
    }
    for(auto i: mst){
        bfs(i);
    }
}