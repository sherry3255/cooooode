/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(int i=0;i < intervals.size();i++){
            int L = intervals[i][0],R = intervals[i][1];
            if(!merged.size() || merged.back()[1] < L){
                merged.push_back({L, R});
            }
            else{
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
// 时间复杂度：O(nlog⁡n)，其中 n 为区间的数量。除去排序的开销，我们只需要一次线性扫描，所以主要的时间开销是排序的 O(nlog⁡n)
// 空间复杂度：O(log⁡n)，其中 n 为区间的数量。这里计算的是存储答案之外，使用的额外空间。O(log⁡n) 即为排序所需要的空间复杂度。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

