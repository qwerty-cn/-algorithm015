/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int low = 1, high = x, result = -1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid > x) {
                high = mid - 1;
            }
            else {
                result = mid;
                low = mid + 1;
            }
        }
        return result;
    }
};
// @lc code=end

//binarysearch：
//关键在于：我们要得到的结果k为k*k <= x的最大k值
