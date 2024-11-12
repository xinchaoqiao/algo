/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

 // @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //nums1最后一个元素后一位
        int one_end = nums1.size();
        nums1.resize(nums1.size() + nums2.size());
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1[one_end] = nums2[i];
            one_end++;
        }

        sort(nums1.begin(), nums1.end());
        double rel = 0;
        if (nums1.size() % 2 == 0) {
            rel = (double)(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        }
        else {
            rel = nums1[(nums1.size() - 1) / 2];
        }
        return rel;
    }
};
// @lc code=end

