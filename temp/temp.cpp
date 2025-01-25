#include <iostream>
using namespace std;
const int N = 10;
int maze_map[N][N];
int v[N][N];
int n, m, t;
int SX, SY, FX, FY;
int cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void dfs(int x, int y) {
    if (x == FX && y == FY) {
        cnt++;
        return;
    }

    for (int i = 0;i < 4;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && maze_map[tx][ty] == 0 && v[tx][ty] == 0) {
            v[tx][ty] = 1;
            dfs(tx, ty);
            v[tx][ty] = 0;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n >> t;
    cin >> SX >> SY >> FX >> FY;

    while (t--) {
        int x, y;
        cin >> x >> y;
        maze_map[x][y] = 1;
    }
    v[SX][SY] = 1;
    dfs(SX, SY);
    cout << cnt << endl;
    return 0;
}