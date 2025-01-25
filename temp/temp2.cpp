#include <iostream>

using namespace std;
const int N = 1e2 + 10;
int maze_map[N][N];
int v[N][N];
int m, n, startx, starty, end_x, end_y, min_step = 0x3f3f3f3f;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// dfs
int dfs(int x, int y, int step) {
    
    if (x == end_x && y == end_y) {
        if (step < min_step) {
            min_step = step;
        }
    }
    if (step > min_step) {
        return step;
    }
    for (int i = 0;i < 4;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx <= n && ty >= 0 && ty <= m && maze_map[tx][ty] == 0 && v[tx][ty] == 0) {
            v[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            v[tx][ty] = 0;
        }
    }
    return min_step;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> maze_map[i][j];
    cin >> startx >> starty >> end_x >> end_y;
    cout << dfs(startx, starty, 0) << endl;
    
    return 0;
}