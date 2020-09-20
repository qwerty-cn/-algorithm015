/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        generate(0, 0, 2*n, "");
        return result;
    }
private:
    vector<string> result;
    void generate(int left, int right, int max, string s) {
        //terminator
        if(left == max / 2 && right == max / 2) {
            result.push_back(s);
            return;
        }
        //process logic
        string s1 = s + '(';
        string s2 = s + ')';
        //drill down
        if(left < max / 2)
            generate(left + 1, right, max, s1);
        if(right < left)
            generate(left, right + 1, max, s2);
        //reverse the status
    }
};
// @lc code=end

