#include <iostream>
using namespace std;
/*
    dfs迷宫
*/
const int N = 1e2 + 10;
int m, n;//迷宫规格
int p, q;//终点坐标
int min_step = 0x3f3f3f3f;//最大值
int maze_map[N][N];// 1空地 2障碍物
int visited[N][N];// 访问过的
void dfs(int x, int y, int step) {
    // 判断是否到终点
    if (x == p && y == q) {
        if (step < min_step) {
            min_step = step;
        }
        return;
    }
    // 优化 避免不必要的递归
    if (step > min_step) return;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };// 试探右下左上四个方向
    //四个方向 循环四次 每个方向都进行试探
    for (int i = 0;i < 4;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (maze_map[tx][ty] == 1 && visited[tx][ty] == 0) {
            visited[tx][ty] = 1;
            dfs(tx, ty, step + 1);// 比如向右试探，那么在这个基础上继续试探 步数需要+1；
            visited[tx][ty] = 0;
        }
    }

    return;
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)// 注意地图起始位置 坐标如果从1 开始算的话 从1 开始 0相同
        for (int j = 0;j < n;j++)
            cin >> maze_map[i][j];
    int startx, starty;
    cin >> startx >> starty >> p >> q;
    visited[startx][starty] = 1;
    dfs(startx, starty, 0);
    cout << min_step << endl;
    return 0;
}