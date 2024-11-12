/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

 // @lc code=start
//s能在p种找到匹配 就能返回成功
 //dp 矩阵右下角字符，代表字符串 s 和 p 能否匹配。
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        //创建一个m行n列的二维容器
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        //s,p 都为空字符为true 匹配成功
        dp[0][0] = true;
        //初始化首行
        for (int j = 2;j < n;j += 2) {
            //因为s首行为空字符,当偶数位是*也可以匹配空字符 对p进行判断 让前面出现0次 及空字符串
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }
        //遍历s  和  p的每一个字符
        for (int i = 1; i < m;i++) {
            for (int j = 1;j < n;j++) {
                //状态转移
                //p[j-1] == '*'情况
                //dp[i][j - 2]： 即将字符组合 p[j - 2] * 看作出现 0 次时，能否匹配
                //dp[i - 1][j] 且 s[i - 1] = p[j - 2]: 即让字符 p[j - 2] 多出现 1 次时，能否匹配。
                //p[j-1] != '*'情况
                dp[i][j] =
                    p[j - 1] == '*' ?
                    dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') :
                    dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
                
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

/*dp[i-1][j-1]：这是当前状态的前一个状态，表示在当前字符之前，两个字符串是否匹配。这是动态规划的核心思想，通过求解子问题来构建最终问题的解。

s[i-1] 和 p[j-1]：这是当前正在处理的字符。s[i-1] 表示字符串 s 的第 i 个字符，p[j-1] 表示模式 p 的第 j 个字符。 */