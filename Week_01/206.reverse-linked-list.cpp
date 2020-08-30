/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return NULL;
        ListNode* reverseHead = nullptr;
        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current != nullptr) {
            ListNode* temp = current -> next;//保存尾地址
            curren -> next = previous;//让当前节点反向
            reverseHead = current;//给输出赋值
            //让previous和current反向，但注意要先赋值previous再赋值current；
            previous = current;
            current = temp;
        }
        return reverseHead;
    }
};
// @lc code=end

