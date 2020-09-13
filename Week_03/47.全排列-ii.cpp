/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<bool> logic(nums.size(), true);
        sort(nums.begin(), nums.end());//这里必须sort，不然会出现元素相同但是不相连的情况，会提高剪枝的复杂度。
        helper(nums, temp, logic);
        return result;
    }
private:
    vector<vector<int> > result;
    void helper(vector<int> &nums, vector<int> &temp, vector<bool> logic) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(logic[i]) {
                if(i > 0 && nums[i] == nums[i-1] && logic[i-1]) continue;//去重逻辑：当前数与前一个数相同且前一个数已经置true时需要跳过该数判断过程
                temp.push_back(nums[i]);
                logic[i] = false;
                helper(nums, temp, logic);
                logic[i] = true;
                temp.pop_back();
                
            }
        }
    }
};
//心得：当遇到有重复数字问题时，要想到排序可以简化问题。
// @lc code=end

