class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ranges::sort(nums);
        int ans, n = nums.size();
        int min_diff = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) {
                continue; // 优化三
            }

            // 优化一
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) { // 后面无论怎么选，选出的三个数的和不会比 s 还小
                if (s - target < min_diff) {
                    ans = s; // 由于下面直接 break，这里无需更新 min_diff
                }
                break;
            }

            // 优化二
            s = x + nums[n - 2] + nums[n - 1];
            if (s < target) { // x 加上后面任意两个数都不超过 s，所以下面的双指针就不需要跑了
                if (target - s < min_diff) {
                    min_diff = target - s;
                    ans = s;
                }
                continue;
            }

            // 双指针
            int j = i + 1, k = n - 1;
            while (j < k) {
                s = x + nums[j] + nums[k];
                if (s == target) {
                    return target;
                }
                if (s > target) {
                    if (s - target < min_diff) { // s 与 target 更近
                        min_diff = s - target;
                        ans = s;
                    }
                    k--;
                } else { // s < target
                    if (target - s < min_diff) { // s 与 target 更近
                        min_diff = target - s;
                        ans = s;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
