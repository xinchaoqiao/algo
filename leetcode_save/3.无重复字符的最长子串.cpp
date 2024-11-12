/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

 // @lc code=start
//滑动窗口:窗口之间都是不重复的字串 set容器中对应的就是right 和left 之间的元素
/*
right不断向右遍历 当set容器里边不存在right对应元素时,添加, 然后right++
有right对应元素时 删除left对应元素直到将与right对应的元素删除 然后right再次添加元素 然后right++
之间就像一个窗口
问题:为什么容器中有right所指元素为什么要删除right在容器中对应的元素
解答: set容器就是right 和left 之间的元素
我们的目的是找到最大长度的无重复子串 就需要把无重复字串都遍历出来 有了这个元素 就 在left处删除 直到找到 新的无重复字串
容器有了这个元素 肯定是right走过的元素 那么操作 left 删除 寻找新的无重复字串 进行长度比对
*/
原理
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, length = 0, maxlength = 0;
        int n = s.length();
        set<char> se;
        while (right < n) {
            if (!se.count(s[right])) {
                se.insert(s[right]);
                length++, right++;
                if (length > maxlength) maxlength = length;
            }
            else {
                while (se.count(s[right])) {
                    se.erase(s[left]);
                    left++;
                    length--;
                }
                se.insert(s[right]);
                right++;
                length++;
            }
        }
        return maxlength;
    }
};

// @lc code=end

