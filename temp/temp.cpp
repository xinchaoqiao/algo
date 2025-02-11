#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// 函数 solution 用于计算最长路径长度
int solution(int m, int n, const std::vector<std::vector<int>>& a) {
    // 检查输入的矩阵维度是否正确

    // 初始化访问标记数组
    std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));

    // 深度优先搜索函数
    std::function<int(int, int, int)> dfs = [&](int x, int y, int k) {
        int ans = 0;
        // 定义四个方向的偏移量
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            // 检查新位置是否越界、是否已访问以及是否满足高度条件
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] || 
                (k == 0 && a[nx][ny] <= a[x][y]) || (k == 1 && a[nx][ny] >= a[x][y])) {
                continue;
            }
            // 标记当前位置为已访问
            vis[x][y] = 1;
            // 递归调用 dfs 函数并更新最长路径长度
            ans = std::max(ans, dfs(nx, ny, k ^ 1) + 1);
            // 回溯，将当前位置标记为未访问
            vis[x][y] = 0;
        }
        return ans;
    };

    int res = 0;
    // 遍历矩阵中的每个位置
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 更新最长路径长度
            res = std::max({res, dfs(i, j, 0), dfs(i, j, 1)});
        }
    }
    return res;
}

int main() {
    // 测试用例 1
    std::vector<std::vector<int>> a1 = {{1, 2}, {4, 3}};
    std::cout << (solution(2, 2, a1) == 3) << std::endl;

    // 测试用例 2
    std::vector<std::vector<int>> a2 = {{10, 1, 6}, {5, 9, 3}, {7, 2, 4}};
    std::cout << (solution(3, 3, a2) == 8) << std::endl;

    // 测试用例 3
    std::vector<std::vector<int>> a3 = {{8, 3, 2, 1}, {4, 7, 6, 5}, {12, 11, 10, 9}, {16, 15, 14, 13}};
    std::cout << (solution(4, 4, a3) == 11) << std::endl;

    return 0;
}