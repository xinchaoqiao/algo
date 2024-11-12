/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            res = max(res, area);
            
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return res;
    }
};
// @lc code=end

