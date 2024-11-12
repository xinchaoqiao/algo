/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

 // @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0;i < nums.size() ;++i) {
            auto it = hash.find(target - nums[i]);//没有找到返回end();
            if (it != hash.end()) {//找到了返回在hash的值 和 索引
                return { it->second,i };
            }
            hash[nums[i]] = i;//索引唯一,这里的值也唯一,以数组nums[i]元素为键  索引为值
        }
        return {};
    }
};
// @lc code=end

