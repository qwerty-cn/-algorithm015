/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //思路：子问题：preorder第一个节点一定是根节点，根据根节点在inorder中确立左子树和右子树的inorder，接着可以将preorder分为左子树和右子树的preorder。然后进行递归即可。
        if(preorder.empty() || inorder.empty()) return nullptr;
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* pRoot = new TreeNode(preorder[preStart]);
        
        int middle = 0; //左右子树的pre/in标签
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] != preorder[preStart]) {
                middle ++;
            }
            else break;
        }

        pRoot->left = helper(preorder, inorder, preStart + 1, preStart + middle - inStart, inStart, middle - 1);
        pRoot->right = helper(preorder, inorder, preStart + middle - inStart + 1, preEnd, middle + 1, inEnd);
        return pRoot;
    }
};
// @lc code=end

