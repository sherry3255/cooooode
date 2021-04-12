/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.24%)
 * Likes:    1177
 * Dislikes: 0
 * Total Accepted:    128.1K
 * Total Submissions: 370.4K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n,0);
        for(int i = 0;i < n;i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = (i>=2?dp[i-2]:0)+2;
                }else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                    // https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/

                    dp[i] = dp[i-1] + (i- dp[i - 1]>=2?dp[i- dp[i - 1]-2]:0)+2;                    
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
// @lc code=end

