/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        helper(n, k, 1);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
    void helper(int n, int k, int startIndex) {
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for(int i = startIndex; i <= n; i++) {
            temp.push_back(i);
            helper(n, k, i + 1);
            temp.pop_back();
        }
    }
};

//回溯递归：模板：在BFS里嵌套DFS
/** 
 * void dfs() {
 *     if(终止条件) {
 *         结果添加
 *     }
 * 
 *     for(可以看成是BFS) {
 *         temp.push_back();//处理当前logic
 *         dfs();//递归
 *         temp.pop_back();//回溯，撤销处理结果。
 *     }
 * } 
 **/
// @lc code=end

