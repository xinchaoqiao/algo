#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
int p, q;//终点坐标
int startx, starty;//开始坐标;
int maze_map[N][N];
int visited[N][N];
int m, n;//迷宫规格
int min_step = 0x3f3f3f3f;
vector<pair<int, int>> path;
vector<pair<int, int>> short_path;
void dfs(int x, int y, int step) {
    if (x == p && y == q) {
        if (step < min_step) {
            min_step = step;
        }
        short_path = path;
        return;
    }
    if (step > min_step) return;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    for (int i = 0;i < 4;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (maze_map[tx][ty] == 0 && visited[tx][ty] == 0 && tx >= 0 && tx <= n && ty >= 0 && ty <= m) {
            path.push_back(make_pair(tx,ty));
            visited[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            visited[tx][ty] = 0;
            path.pop_back();
        }
    }
    return;
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> maze_map[i][j];
    cin >> startx >> starty >> p >> q;
    visited[startx][starty] = 1;
    dfs(startx,starty, 0);
    cout << min_step << endl;
    for (auto t : short_path) {
        cout << t.first << ' ' << t.second << endl;
    }
    return 0;
}