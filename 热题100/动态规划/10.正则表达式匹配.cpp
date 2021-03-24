/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.56%)
 * Likes:    1882
 * Dislikes: 0
 * Total Accepted:    145.5K
 * Total Submissions: 471.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aa" p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：s = "aa" p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab" p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "aab" p = "c*a*b"
 * 输出：true
 * 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "mississippi" p = "mis*is*p*."
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=2;j<=n;j++)
        {
            dp[0][j]=p[j-1]=='*'&&dp[0][j-2];//再往后 dp[0][2]，p[1] = '*'，它可以选择消除掉第一个字符a，那么这个子串就也变成了一个空串，
                                             // 因此是匹配的。再往后推，dp[0][3]为 false，dp[i][4] 因为 p[3]是 '*' 所以可以消除掉前面的b，
                                             //同时第一个 '*' 可以消除掉 a，所以整体p又变成了一个空串，是匹配的。
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')//s[i-1] == p[j-1]
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(j>1&&s[i-1]!=p[j-2]&&p[j-2]!='.')//p[j-2] != s[i-1]
                    {
                        dp[i][j]=dp[i][j-2];
                    }
                    else//p[j-2] = s[i-1]
                    {
                        dp[i][j]=dp[i][j-2]||dp[i][j-1]||dp[i-1][j];//1. s = 'abc', p = "abcc*";  
                                                                    //2. s = "abc", p = "abc*";
                                                                    //3.  s = "abcc" or "abccc" or "abcccc..", p = "abc*"
                    }
                }
            }
        }
        return dp[m][n];
    }
};

// @lc code=end

