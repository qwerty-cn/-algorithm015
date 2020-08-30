/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //设置两个指针，一个遍历全部，另一个指向不是0的元素，然后将非0元素全部前移。    其实是两个元素的互换
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                if(i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};
// @lc code=end

