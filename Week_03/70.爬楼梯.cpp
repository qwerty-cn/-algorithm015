/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        //法1：动态规划
        // int fir = 1, sec = 2;
        // int result;
        // if(n <= 0) return 0;
        // else if(n == 1) return fir;
        // else if(n == 2) return sec;
        // else {
        //     for(int i = 3; i <= n; i++) {
        //         result = fir + sec;
        //         fir = sec;
        //         sec = result;
        //     }
        //     return result;
        //法2：这里用vector来保存每一个中间变量；
        vector<int> result(n + 1, -1);
        return helper(n, result);
        }
private:
    int helper(int max, vector<int> &result) {
        if(max < 0) return 0;
        else if(max == 0) return 1;
        else {
            if(result[max] != -1) return result[max];
            else return result[max] =  helper(max - 1, result) + helper(max - 2, result);
        }
    }
};
//思路：动态规划 - 最后一步时有两种可能，一种是走一步，一种是走两步，所以状态转移方程为f(n) = f(n - 1) + f(n - 2)；
//如果用递归，需要自己维护一个容器来保存中间结果，这样才能更加高效。
// @lc code=end

