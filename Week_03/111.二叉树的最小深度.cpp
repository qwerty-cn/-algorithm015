/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {//DFS:对于非叶节点，其左右子树深度最小值+1即为该树的最小深度。
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        int mindepth = INT_MAX;
        if(root->left != nullptr) mindepth = min(mindepth, minDepth(root->left));
        if(root->right != nullptr) mindepth = min(mindepth, minDepth(root->right));

        return mindepth + 1;
    }
};//关键之处：必须是非叶节点，如果是叶节点，有可能出现[1,1]这种情况下判断最小深度为0的情况，实际结果为2
// @lc code=end

