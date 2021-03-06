/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (40.01%)
 * Likes:    979
 * Dislikes: 0
 * Total Accepted:    111.5K
 * Total Submissions: 273.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // need为需要的字符，window为窗口内的字符
        unordered_map<char, int> need, window;
        for(auto c : t) need[c]++;
        int left =0,right = 0;
        // valid为判断窗口内的字符是否满足t需要的字符，并记录最小覆盖子串的初始长度及索引
        int valid = 0,maxlen = s.size()+1,start = left;
        while(right < s.size()){
            // 要移入窗口的字符
            char c = s[right];
            // 右移窗口
            right ++;
            // 需要字符串c，更新valid判断
            if (need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid ++;
                }
            }

            // 判断左侧窗口是否收缩
            // 当窗口中满足所有的t字符要求，即收缩左侧窗口
            while(valid == need.size()){
                if(right - left < maxlen){
                    start = left;
                    maxlen = right - left;
                }
                char d = s[left];
                left ++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return maxlen == s.size()+1?"":s.substr(start,maxlen);
    }
};
// @lc code=end

