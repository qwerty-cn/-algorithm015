/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //法1 part1
        // vector<int> temp;
        // int length = nums.size() - 1;
        // vector<bool> logic(length, true);
        // helper(temp, nums, logic);
        //return result;

        //法2 part2
        int max = nums.size();
        helper(0, nums, max);
        return result;
    }
private:
    vector<vector<int>> result;
    //法1 part2
    // void helper(vector<int> temp, vector<int> &nums, vector<bool> &logic) {
    //     if(temp.size() == nums.size()) {
    //         result.push_back(temp);
    //         return;
    //     }

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(logic[i]) {
    //             temp.push_back(nums[i]);//当前处理逻辑
    //             logic[i] = false;
    //             helper(temp, nums, logic);
    //             logic[i] = true;
    //             temp.pop_back();//当前逻辑回溯
    //         }
    //     }
    // }

    //法2 part2
    void helper(int begin, vector<int> temp, int max) {
        if(begin == max) {
            result.push_back(temp);
            return;
        }

        for(int i = begin; i < max; i++) {
            swap(temp[i], temp[begin]);
            helper(begin+1, temp, max);
            swap(temp[i], temp[begin]);
        }
    }
};
//思路：1.回溯法1：利用一个vector来存放已作出的选择，然后进行搜索回溯。
//     2.回溯法2：全排列有顺序关系，所以无论如何，输入数组中的所有元素都会在出现在输出中，只需要遍历所有元素的顺序即可。那么可以利用标记的方式将已遍历和未遍历的元素分开。
// @lc code=end

