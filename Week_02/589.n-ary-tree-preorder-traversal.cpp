/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preOrder; //vector的默认初始化方式，插入元素只能用push_back
    vector<int> preorder(Node* root) {
        if(root == nullptr) return {};
        preOrder.push_back(root->val);
        if(!root->children.empty()) {
            for(int i = 0; i < root->children.size(); i++) {
                preorder(root->children[i]);
            }
        }
        return preOrder;
    }
};
// @lc code=end

