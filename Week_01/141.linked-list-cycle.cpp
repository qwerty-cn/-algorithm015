/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *fast = head, *slow = head; //双指针的思路，慢走一步快走两步
        while(fast && fast->next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }
        return false;
    }
};
// @lc code=end

