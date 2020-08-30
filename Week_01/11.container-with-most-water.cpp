#include<iostream>
#include<vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int result = 0;
        int h;
        while(high > low) {
            if(height[high] > height[low]) {
                h = height[low];
                low++;
            }
            else {
                h = height[high];
                high--;
            }
            if(result < h*(high - low + 1))
                result = h*(high - low + 1);
        }
        return result;
    }
};
// @lc code=end

