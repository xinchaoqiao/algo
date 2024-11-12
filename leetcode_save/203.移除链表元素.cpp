/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
//这个可以把每个cur看成一个链表的头节点 如果不进行保存cur节点为tmp 然后 delete tmp 那么 cur 后边的节点也会到dummy上
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //头节点不存在
        if (!head) return nullptr;

        //前续节点
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        while (cur && cur->val == val) {
            cur = cur->next;
        }
        //中间节点

        dummy->next = cur;//把当前节点看作头节点 后续的cur变更对dummy无影响 后续节点地址改变会影响到dummy (修改地址)
        while (cur && cur->next) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;//delete 对 dummy有影响 cur对dummy后续节点(地址)进行了修改(删除) 细节:后续cur将cur下一个的地址指向改变了 
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

