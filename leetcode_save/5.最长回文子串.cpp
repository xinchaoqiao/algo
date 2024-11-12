/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

 // @lc code=start

//中心扩展算法
class Solution {
public:
    pair<int,int> extend(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[right] == s[left]) {
            left--;
            right++;
        }
        return { left + 1,right - 1 };
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int n = s.length();
        for (int i = 0; i < n;i++) {
            auto [left1,right1] =  extend(s, i, i);
            auto [left2,right2] = extend(s, i, i + 1);

            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);//函数解释: 从start开始截取,截取长度为end-start+1;
    }
};
// @lc code=end

