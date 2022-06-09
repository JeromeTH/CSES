#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1 << 17;
vector<pair<int, int>> e[SIZE];
int it[SIZE], deg[SIZE];
bitset<SIZE> used;
vector<int> answer;
void dfs(int x) {
    for(int &i = it[x]; i < SZ(e[x]); i++) {
        if(!used[e[x][i].second]) {
            used[e[x][i].second] = 1;
            dfs(e[x][i].first);
        }
    }
    answer.PB(x);
}
void solve() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a].PB(MP(b, i));
        e[b].PB(MP(a, i));
        deg[a] ^= 1;
        deg[b] ^= 1;
    }
    if(count(deg, deg + n + 1, 1)) {
         puts("IMPOSSIBLE");
    } else {
        dfs(1);
        if(SZ(answer) <= m) { puts("IMPOSSIBLE"); }
        else {
            for(int i = 0; i < SZ(answer); i++) {
                printf("%d%c", answer[i], " \n"[i == SZ(answer) - 1]);
            }
        }
    }
}
int main() {
    solve();
    return 0;
}