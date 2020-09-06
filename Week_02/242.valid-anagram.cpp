/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        //思路：1.暴力，sort，然后判断sorted_str是否一样（O(nlogn)） 2.hash, map
        // //sort
        // if(s.length() != t.length()) return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        //hash
        if(s.length() != t.length()) return false;
        unordered_map<char, int> hash;
        for(int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto it = hash.begin(); it != hash.end(); it++) {
            if(it->second != 0) return false;
        }
        return true;
    }
};
// @lc code=end

