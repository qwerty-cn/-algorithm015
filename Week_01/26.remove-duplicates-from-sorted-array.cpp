/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int firPtr = 0,secPtr = 0;
        while(secPtr != nums.size()-1){
            if(nums[secPtr] != nums[secPtr+1]){
                nums[++firPtr] = nums[secPtr+1];
            }
            secPtr++;
        }
        return firPtr+1;
    }
};
// @lc code=end

