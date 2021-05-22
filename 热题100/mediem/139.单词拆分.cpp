/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (48.69%)
 * Likes:    847
 * Dislikes: 0
 * Total Accepted:    120.6K
 * Total Submissions: 245K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for(auto word:wordDict){
            wordDictSet.insert(word);
        }
        auto dp = vector<bool> (s.size()+1);
        dp[0] = true;
        for(int i=1;i <= s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && wordDictSet.find(s.substr(j,i-j))!=wordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
/*

时间复杂度：O(n^2) ，其中 n 为字符串 s 的长度。我们一共有 O(n) 个状态需要计算，每次计算需要枚举 O(n)个分割点，哈希表判断一个字符串是否出现在给定的字符串列表需要 O(1)的时间，因此总时间复杂度为 O(n^2)。

空间复杂度：O(n) ，其中 n 为字符串 s 的长度。我们需要 O(n) 的空间存放 dp 值以及哈希表亦需要 O(n)的空间复杂度，因此总空间复杂度为 O(n)。

*/
