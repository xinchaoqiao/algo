/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x >= -9 && x <= 9) return x;
        long long res = 0;
        int flag = 1;
        if (x < 0) flag = -1;
        int temp = abs(x);
        while (temp > 0) {
            long long dig = temp % 10;
            temp /= 10;
            res = res * 10 + dig;
        }
        if (flag == -1) res = -res;
        if (res > INT_MAX || res < INT_MIN) return 0;
        //如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0
        return res;
    }
};
// @lc code=end

