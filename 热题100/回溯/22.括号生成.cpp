/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.62%)
 * Likes:    1579
 * Dislikes: 0
 * Total Accepted:    231.9K
 * Total Submissions: 301.7K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 使用一个变量 balance 表示左括号的数量减去右括号的数量。如果在遍历过程中 balance 的值小于零，或者结束时 balance 的值不为零，那么该序列就是无效的，否则它是有效的。

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(current, n, 0, 0, result);
        return result;
    }
    void backtrack(string &current, int n, int open, int close, vector<string>& result){
        if(current.size() == 2*n){
            result.push_back(current);
        }
        if(open < n){
            current.push_back('(');
            backtrack(current, n, open+1, close, result);
            current.pop_back();
        }
        if(close < open){
            current.push_back(')');
            backtrack(current, n, open, close + 1, result);
            current.pop_back();
        }
    }
    
};
// 时间复杂度和空间复杂度直接看链接https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
// @lc code=end

