/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> gg;
    bool row[10], col[10], dg[20], udg[20];
    void dfs(int x, int y, int s, int n) {
        vector<string> g;
        if (s > n) return;
    if (y == n) {
        y = 0;
        x++;
    }

    if (x == n) {
        if (s == n) {
            for (auto v : gg) {
                for (auto vv : v) {
                    cout << vv;
                }
            }
            puts("");
        }
        return;
    }

    dfs(x, y + 1, s,n);

    if (!row[x] && !col[y] && !dg[y - x] && !udg[y - x + n]) {
        gg[x][y] = 'Q';
        row[x] = col[y] = dg[y - x] = udg[y - x + n] = true;
        dfs(x, y + 1, s + 1,n);
        gg[x][y] = '.';
        row[x] = col[y] = dg[y - x] = udg[y - x + n] = false;
    }
}
    
    vector<vector<string>> solveNQueens(int n) {
        dfs(0, 0, 0,n);
        return gg;
    }
};
// @lc code=end

