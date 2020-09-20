/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
// class Solution {
// public:
//     int minMutation(string start, string end, vector<string>& bank) {
//         queue<string> q;
//         unordered_map<string, bool> hash;
//         for(auto& str : bank) {
//             hash[str] = false;
//         }
//         q.push(start);
//         hash[start] = true;

//         int time = 0;
//         while(!q.empty()){
//             int len = q.size();
//             for(int i = 0; i < len; i++){
//                 string topStr = q.front();
//                 q.pop();
//                 if(topStr == end) return time;
//                 for(int j = 0; j < 8; j++) {
//                     string tempStr = topStr;//这里必须重新定义变量，因为后面要更改参数
//                     for(int k = 0; k < 4; k++) {
//                         tempStr[j] = table[k];
//                         if(hash.count(tempStr) > 0 && !hash[tempStr]) {
//                             q.push(tempStr);
//                             hash[tempStr] = true;
//                         }
//                     }
//                 }
//             }
//             time++;
//         }
//         return -1;
//     }
// private:
//     const char table[4] = {'A', 'C', 'G', 'T'};
// };
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(bank.begin(), bank.end());

        if(dict.count(end) == 0) return -1;
        int ans = 0;
        int len = start.size();
        s1.insert(start);
        s2.insert(end);

        while(!s1.empty() && !s2.empty()) {
            ans++;
            if(s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> cur;
            for(auto g : s1) {
                for(int i = 0; i < len; i++){
                    char temp = g[i];
                    for(char x : "ACGT") {
                        g[i] = x;
                        if(s2.count(g) > 0) return ans;
                        if(dict.count(g) > 0){
                            cur.insert(g);
                            dict.erase(g);
                        }
                    }
                    g[i] = temp;
                }
            }
            s1 = cur;
        }
        return -1;
    }
};
// @lc code=end

//思路：bfs
//把start想象成树的root，每层出现4种变化（ACGT）
//每次遍历按层序遍历，若出现在基因库（用hash来记录）中就继续往深遍历，直到遍历到end序列，最后的层数就是需要的基因突变次数。

//更好的办法：双向BFS