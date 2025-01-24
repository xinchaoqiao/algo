#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
int p, q;//终点坐标
//int startx, starty;//开始坐标;
int map[N][N];
int visited[N][N];
int m, n;//迷宫规格
int min_step = 0x3f3f3f3f;
vector<pair<int, int>> v;
void dfs(int x, int y, int step) {
    if (x == p && y == q) {
        if (step < min_step) {
            min_step = step;
        }
        // for (auto t : v) {
        //     cout << "(" << t.first << "," << t.second << ")" << endl;
        // }
        return;
    }
    if (step > min_step) return;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    for (int i = 0;i < 4;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (map[tx][ty] == 0 && visited[tx][ty] == 0 && tx >= 0 && tx <= n && ty >=0 && ty <=m) {
            visited[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            visited[tx][ty] = 0;
        }
    }
    return;
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> map[i][j];
    p = m - 1, q = n - 1;
    visited[0][0] = 1;
    dfs(0, 0, 0);
    cout << min_step << endl;
    return 0;
}