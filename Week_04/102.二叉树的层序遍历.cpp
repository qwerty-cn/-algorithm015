/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<vector<int> > result;
        queue<TreeNode*> node;
 
        node.push(root);
        while(!node.empty()){
            vector<int> visited;
            int len = node.size();
            while(len) {
                TreeNode* parent = node.front();
                visited.push_back(parent->val);
                node.pop();
                
                if(parent->left) node.push(parent->left);
                if(parent->right) node.push(parent->right);
                len--;  
            }
            result.push_back(visited);    
        }    
        return result;
    }
};
//思路：将父节点送入队列，并记录当前父节点的个数。依次将父节点弹出和对应的子节点送入。每次父节点个数清零时返回一次vector。
// @lc code=end

