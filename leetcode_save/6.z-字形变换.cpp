/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

 // @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        /*
        输入：s = "PAYPALISHIRING", numRows = 3
        输出："PAHNAPLSIIGYIR"
        N字形变换:rows[i].push_back(c);直接插入到行的末尾
        */

        //只想遍历容器直接增强for遍历
        if (numRows < 2) return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);//新点 将字符串 c 添加到 rows 的第 i 行的末尾。
            if (i == 0 || i == numRows - 1) flag = -flag;//Z变换核心
            i += flag;
        }
        string rel;
        for (const string &row : rows) {
            rel += row;
        }
        return rel;
    }
};
// @lc code=end

