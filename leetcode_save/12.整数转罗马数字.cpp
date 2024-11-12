/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

 // @lc code=start
class Solution {
public:
    const pair<int, string> valueSymbols[13] = {
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"},
    };

    string intToRoman(int num) {
        string roman;
        for (const auto& [value, symbol] : valueSymbols) {//先定外循环,内循环while不断找不大于num的最大罗马数字
            while (num >= value) {
                num -= value;//循环寻找当前最大的罗马数字
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};
// @lc code=end

