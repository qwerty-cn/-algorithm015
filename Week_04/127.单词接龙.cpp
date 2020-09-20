/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        int len = beginWord.size();
        int ans = 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        if(dict.count(endWord) == 0) return 0;
        while(!s1.empty() && !s2.empty()) {
            ans++;
            if(s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> cur;
            for(auto w : s1) {
                for(int i = 0; i < len; i++) {
                    char temp = w[i];
                    for(int x = 'a'; x <= 'z'; x++) {
                       w[i] = x;
                       if(s2.count(w) > 0) return ans + 1;
                       if(dict.count(w) > 0) {
                           cur.insert(w);
                           dict.erase(w);
                       }
                    }
                    w[i] = temp;
                }
            }
            s1 = cur;
        }
        return 0;
    }
};
// @lc code=end
//思路：双向bfs：确立两个set用来保存从头到尾遍历（s1）和从尾到头遍历（s2）的结果，每次遍历取较小size的set
//当s1与s2中遍历的string碰面时说明路径找到。
