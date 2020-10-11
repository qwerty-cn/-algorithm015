/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // vector<vector<int> > dp(m+1, vector<int> (n+1, 0));
        // dp[0][1] = 1;//本身不影响初始化，但方便了初始化
        // for(int i = 1; i <= m; i++) {//因为这里相当于多移了一位，所以要等于号
        //     for(int j = 1; j <= n; j++) {
        //         if(obstacleGrid[i-1][j-1] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }

        // return dp[m][n];

        //法2：
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else if(j>0) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

//与不同路径相比：多了障碍物 就意味着：1.有些地方不能直接加了，需要剪枝 2.（也是刚开始做题忽略的一点）初始化时候不一样了。
//一个好的点子：建立一个dp[m+1][n+1]的状态矩阵，然后将dp[0][1] = 1，接下来的所有值根据obstacleGrid来进行计算，只有当obstacleGrid[i-1][j-1] == 0时才能使用状态方程进行求解。
//同样的，我们只需要1个矩阵来进行叠加即可。