/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // int len1 = text1.size(), len2 = text2.size();
        // vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
        // for(int i = 1; i <= len1; i++) {
        //     for(int j = 1; j <= len2; j++) {
        //         if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // return dp[len1][len2];

        //法2：只需要两个Vector就可以完成(相邻的两行)
        int len1 = text1.size(), len2 = text2.size();
        vector<int> pre(len2+1, 0), cur(len2+1, 0);
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if(text1[i-1] == text2[j-1]) cur[j] = pre[j-1] + 1;
                else cur[j] = max(pre[j], cur[j-1]);
            }
            swap(pre, cur);
        }
        // return pre[len2];//最后一次时候pre和cur互换了 所以需要输出pre而不是cur
    }
};

//思路：二维动态规划：行为text1，列为text2
//dp(i, j) -> 当前位置的最大公共子序列数
//dp[i][j] = {
//  1.若s1[i-1] = s2[j-1], dp[i][j] = dp[i-1][j-1] + 1
//  2.否则，dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//}
// @lc code=end

