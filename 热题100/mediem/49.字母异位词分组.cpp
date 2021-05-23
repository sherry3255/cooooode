/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (65.26%)
 * Likes:    668
 * Dislikes: 0
 * Total Accepted:    166.6K
 * Total Submissions: 254.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s:strs){
            string key = s;
            sort(key.begin(),key.end());
            mp[key].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it!=mp.end();it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
/*
时间复杂度：O(nklog⁡k)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。
需要遍历 n 个字符串，对于每个字符串，
需要 O(klog⁡k) 的时间进行排序以及 O(1) 的时间更新哈希表，因此总时间复杂度是 O(nklog⁡k)。

空间复杂度：O(nk)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。
需要用哈希表存储全部字符串。
*/
// @lc code=end

