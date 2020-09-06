/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0) return {};
        vector<int> result;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m.insert(make_pair(nums[i], i));
        }

        for(int j = 0; j < nums.size(); j++) {
            if(m.count(target - nums[j]) > 0 && j != m[target - nums[j]]) {
                result.push_back(j);
                result.push_back(m[target - nums[j]]);
                break;
            }
        }
        return result;
    }
};
// @lc code=end

