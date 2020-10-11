/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //法1：二维DP - 时间复杂度O(n^2)，空间复杂度O(n^2)
        // int m = triangle.size();
        // vector<vector<int> > dp(m, vector<int>(m, 0));
        // dp[0][0] = triangle[0][0];
        // for(int i = 1; i < m; i++) {
        //     for(int j = 0; j <= i; j++) {
        //         if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
        //         else if(j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
        //         else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]; 
        //     }
        // }
        // return *min_element(dp[m-1].begin(), dp[m-1].end());

        //法2：利用一个一维Vector
        int m = triangle.size();
        vector<int> dp(m, triangle[0][0]);
        for(int i = 1; i < m; i++) {
            for(int j = i; j >= 0; j--) {
                if(j == 0) dp[j] += triangle[i][j];
                else if(j == i) dp[j] = dp[j-1] + triangle[i][j];
                else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

