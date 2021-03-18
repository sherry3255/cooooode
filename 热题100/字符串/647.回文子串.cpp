/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (64.60%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    80.8K
 * Total Submissions: 124.4K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),ans = 0;
        for(int i = 0;i < 2*n-1;i++){
            int l = i/2,r = i/2+i%2;
            while(l>=0 && r<n && s[l] == s[r]){
                r++;
                l--;
                ans++;
            }
        }
        return ans;
    }
};
// 时间复杂度 o(n^2),主要是指针会移动n次，每次最多遍历n位，空间复杂度o(1)
// @lc code=end

