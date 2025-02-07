#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

// 定义一个结构体来表示二维坐标
using Coordinate = std::pair<int, int>;

// 解决方案函数
int solution(int N, int M, const std::vector<std::vector<char>>& data) {
    // 检查输入数据的维度是否正确

    // 定义方向映射
    std::vector<std::pair<int, int>> dir_mp = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<std::vector<bool>> vis(N, std::vector<bool>(M, false));
    std::queue<Coordinate> q;

    // 找到所有 'O' 位置并加入队列
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (data[i][j] == 'O') {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        ans++;
        Coordinate current = q.front();
        q.pop();
        int sx = current.first;
        int sy = current.second;

        // 遍历四个方向
        for (const auto& dir : dir_mp) {
            int dx = dir.first;
            int dy = dir.second;
            int x = sx + dx;
            int y = sy + dy;

            // 检查坐标是否在合法范围内且未被访问过
            if (0 <= x && x < N && 0 <= y && y < M &&!vis[x][y]) {
                if (data[x][y] == 'U' || data[x][y] == 'D' || data[x][y] == 'L' || data[x][y] == 'R') {
                    std::pair<int, int> newDir;
                    switch (data[x][y]) {
                        case 'U':
                            newDir = {-1, 0};
                            break;
                        case 'D':
                            newDir = {1, 0};
                            break;
                        case 'L':
                            newDir = {0, -1};
                            break;
                        case 'R':
                            newDir = {0, 1};
                            break;
                    }
                    if (x + newDir.first == sx && y + newDir.second == sy) {
                        vis[x][y] = true;
                        q.push({x, y});
                    }
                } else {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

    return N * M - ans;
}

int main() {
    // 测试用例 1
    std::vector<std::vector<char>> data1 = {
        {'.', '.', '.', '.', '.'},
        {'.', 'R', 'R', 'D', '.'},
        {'.', 'U', '.', 'D', 'R'},
        {'.', 'U', 'L', 'L', '.'},
        {'.', '.', '.', '.', 'O'}
    };
    std::cout << (solution(5, 5, data1) == 10) << std::endl;

    // 测试用例 2
    std::vector<std::vector<char>> data2 = {
        {'.', 'R', '.', 'O'},
        {'U', '.', 'L', '.'},
        {'.', 'D', '.', '.'},
        {'.', '.', 'R', 'D'}
    };
    std::cout << (solution(4, 4, data2) == 2) << std::endl;

    // 测试用例 3
    std::vector<std::vector<char>> data3 = {
        {'.', 'U', 'O'},
        {'L', '.', 'R'},
        {'D', '.', '.'}
    };
    std::cout << (solution(3, 3, data3) == 8) << std::endl;

    return 0;
}