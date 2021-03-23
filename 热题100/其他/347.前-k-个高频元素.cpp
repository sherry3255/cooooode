/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second >n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ocur;
        for(auto &v:nums){
            ocur[v]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> tr(cmp);
        for(auto& [num, count] : ocur){
            if(tr.size() == k){
                if(tr.top().second < count){
                    tr.pop();
                    tr.emplace(num,count);
                }
            }else{
                tr.emplace(num,count);
            }
        }
        vector<int> ret;
        while(!tr.empty()){
            ret.emplace_back(tr.top().first);
            tr.pop();
        }
        return ret;
    }
};
/*
时间复杂度：O(Nlog⁡k)，其中 N 为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，共需 O(N) 的时间。随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 O(log⁡k) 的时间，共需 O(Nlog⁡k) 的时间。二者之和为 O(Nlog⁡k)。
空间复杂度：O(N)。哈希表的大小为 O(N)，而堆的大小为 O(k)，共计为 O(N)。

*/
// @lc code=end

