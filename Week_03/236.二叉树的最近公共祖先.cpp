/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //思路：遍历树结构，会出现两种大情况：一种是左右子树各存在一个节点、另一种是节点只存在子树中的其中一个。
        //当左右子树都存在时，要返回当前根节点
        //当只存在其中一个子树时，就需要判断是左子树还是右子树
        //边界条件：root == null, root == q || root == p
        
        //4 steps:terminator, process logic, drill down, reverse the current states
        if(root == nullptr) return nullptr;
        else if(root == p || root == q) return root;

        else {
            //遍历 -> 递归
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);

            //判断：
            //如果存在在两个不同的子树上：
            if(left && right) return root;
            //如果只存在一个子树上：
            return left ? left : right;
            
            //第一次这样写的，效果不好，因为没有把所有情况考虑进去，会出现不返回结果的情况。
            // if(left == nullptr) return right;
            // if(right == nullptr) return left;
        }
    }
};
//高分题解中有句话说的很好：因为是递归，使用函数后可认为左右子树已经算出结果。
// @lc code=end

