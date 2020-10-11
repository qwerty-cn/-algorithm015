/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 1));
//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };

//思路：动态规划
//3步走：
//1.最优子问题：当前一步的路径和dp(i,j) = 往右一步走的所有路径和dp(i-1, j) + 往下走一步的路径和dp(i, j-1)
//2.定义状态空间：路径和dp[i][j]
//3.状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
//4.初始化：如果一直往下或者一直往右走，其实是一条路，所以dp[0][j] = dp[i][0] = 1

//更进阶的办法：优化内存。本身其实是一个自己叠加的过程，所以不需要存储中间结果，所以理论来说只需要一个一维vector就可以一直保存结果。

public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }

        return dp[n-1]; // 返回的肯定是最后一项。
    }
};
// @lc code=end

