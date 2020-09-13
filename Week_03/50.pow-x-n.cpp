/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        //terminator, process logic, drill down, reverse the current states
        //分治：将问题分解成子问题然后再合并。
        //思路1：迭代，时间复杂度O(n)
        //思路2：分治递归：时间复杂度O(logn)
        long long N = n;
        return N >= 0 ? binaryPow(x, N) : 1/binaryPow(x, -N);
    }
private:
    double binaryPow(double x, int n) {
        if(n == 0) return 1;
    
        double half = binaryPow(x, n / 2);

        return n % 2 == 0 ? half*half : half*half*x;
    }
};
// @lc code=end

