/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //terminator
        if(root == nullptr) return nullptr;
        //process logic
        swap(root->left, root->right);
        //drill down
        invertTree(root->left);
        invertTree(root->right);
        //reverse the states
        return root;
    }
};
// @lc code=end

