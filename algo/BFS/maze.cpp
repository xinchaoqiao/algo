#include <iostream>
#include <queue>
using namespace std;

const int N = 1e2 + 10;
int maze_map[N][N],v[N][N];
int m, n; // 迷宫规模
int startx, starty, end_x, end_y;//起点 终点
// 方向矢量
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

class point
{
public:
    int x, y, step;
    point(int x, int y, int step);
};

point::point(int x,int y,int step)
{
    this->x = x;
    this->y = y;
    this->step = step;
}

queue<point> q;

int bfs() {
    point start(startx, starty, 0);
    q.push(start);
    v[startx][starty] = 1;
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
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && v[tx][ty] == 0 && maze_map[tx][ty] == 0) {
                point tm(tx, ty, q.front().step + 1);
                q.push(tm);
                v[tx][ty] = 1;
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



/* #include <iostream>
#include <queue>
using namespace std;
const int N = 1e2 + 10;
int m, n;//迷宫规模
int maze_map[N][N];//迷宫 // 0 平地 1 障碍物
int v[N][N];//访问数组
int startx, starty, end_x, end_y;//开始坐标 & 结束坐标
// 偏移量
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct point
{
    int x;
    int y;
    int step;
};

queue<point> r;

void bfs() {
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;
    r.push(start);// 起点入队
    v[startx][starty] = 1;
    int flag = 0;

    while (!r.empty()) {
        int x = r.front().x, y = r.front().y;

        // 判断是否到达终点
        if (x == end_x && y == end_y) {
            flag = 1;
            break;
        }

        //  向4个方向拓展
        for (int i = 0;i < 4;i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            //在迷宫内 & 未访问 & 不是障碍物 入队
            if (tx >= 0 && tx <= n && ty >= 0 && ty <= m && v[tx][ty] == 0 && maze_map[tx][ty] == 0) {

                point tm;
                tm.x = tx;
                tm.y = ty;
                tm.step = r.front().step + 1;
                r.push(tm);
                v[tx][ty] = 1;
            }
        }
        //队头出队
        r.pop();
    }
    if (flag == 0) cout << "No Answer !!!" << endl;
    else cout << r.front().step << endl;
    return;
}
int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> maze_map[i][j];
    cin >> startx >> starty >> end_x >> end_y;
    bfs();
    
    return 0;
} */


