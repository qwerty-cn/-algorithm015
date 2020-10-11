/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp(k) ：最大金额 
        //dp[k] = max(dp[k-1], nums[k-1] + dp[k-2])
        // if (nums.size() == 0) {
        //     return 0;
        // }
 
        // int N = nums.size();
        // vector<int> dp(N+1, 0);
        // dp[0] = 0;
        // dp[1] = nums[0];
        // for (int k = 2; k <= N; k++) {
        //     dp[k] = max(dp[k-1], nums[k-1] + dp[k-2]);
        // }
        // return dp[N];

        //考虑到只用到了dp[k-1]和dp[k-2],所以只需要两个变量就可以完成
        int prev = 0;
        int curr = 0;

        for (int i : nums) {
            int temp = max(curr, prev + i);
            prev = curr;
            curr = temp;
        // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
        }
        return curr;
    }
};
// @lc code=end

