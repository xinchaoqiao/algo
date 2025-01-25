#include <iostream>
#include <queue>

using namespace std;
const int N = 1e2 + 10;
int maze_map[N][N];
int v[N][N];
int m, n;
int startx, starty, end_x, end_y;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

class point
{

public:
    int x, y, step;
    point(int x, int y, int step) {
        this->x = x;
        this->y = y;
        this->step = step;
    }
};

queue<point> q;

int bfs() {
    // 加入第一个点
    point start(startx, starty, 0);
    q.push(start);
    int flag = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;

        // 判断是否到达终点
        if (x == end_x && y == end_y) {
            flag = 1;
            break;
        }

        for (int i = 0;i < 4;i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx <= n && ty >= 0 && ty <= m && v[tx][ty] == 0 && maze_map[tx][ty] == 0) {
                point tm(tx, ty, q.front().step + 1);
                q.push(tm);
            }
        }
        q.pop();
    }
    if (!flag) {
        cout << "No Answer !!!" << endl;
        return -1;
    }
    return q.front().step;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> maze_map[i][j];
    cin >> startx >> starty >> end_x >> end_y;
    cout << bfs() << endl;

    return 0;
}