/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for(int i = 0; i < nums.size(); i++) {
            fre[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        for(auto iter = fre.begin(); iter != fre.end(); iter++) {
            if(k == pq.size()) {//队列已经填满
                if(iter->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            } else {
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        //reverse(result.begin(), result.end());
        return result;
    }
};
//思路：1. hash表存入元素，其中first代表元素，second代表频次，然后根据second进行排序，把前K个输出 - 存+排太慢了
//2.堆、优先队列 - 每次输出频次最大的key值，时间复杂度为O(NlogK) 3.快排
// @lc code=end

