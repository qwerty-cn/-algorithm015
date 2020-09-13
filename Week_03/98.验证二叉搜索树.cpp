/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // //1.递归：判断值是否在区间之内
    // bool isValidBST(TreeNode* root) {
    //     return helper(root, LONG_MIN, LONG_MAX);
    // }
    // bool helper(TreeNode* root, long long lower, long long higher) {
    //     if(root == nullptr) return true;

    //     if(root->val <= lower || root->val >= higher) return false;

    //     return helper(root->left, lower, root->val) && helper(root->right, root->val, higher);
    // }
    bool isValidBST(TreeNode* root) {
        //2.中序遍历：如果是BST，那么中序遍历是升序序列。
        long lower = LONG_MIN;
        return helper(root, lower);
    }
    bool helper(TreeNode* root, long long pre) {
        if(root == nullptr) return true;

        if(!helper(root->left, pre)) return false;

        if(root->val <= pre) return false;
        pre = root->val;
        
        return helper(root->right, pre); 
    }
// private:
//     long long lower = LONG_MIN;
};
// @lc code=end

