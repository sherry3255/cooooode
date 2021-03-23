/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;// 起始下标
        int left = 0,right = 0, valid = 0;
        unordered_map<char, int> windows, needs;
        for(char c:p) needs[c]++;
        // 先扩张右边，右边valid满足之后，再缩减左边
        while(right < s.size()){
            char ch = s[right];
            right++;
            if(needs.count(ch)){
                windows[ch]++;
                if(windows[ch] == needs[ch])
                    valid++;
            }
            while(valid == needs.size()){
                if(right - left == p.size()){
                    res.push_back(left);
                }
                char ch = s[left];
                left++;
                if(needs.count(ch)){
                    if(windows[ch] == needs[ch]){
                        valid--;
                    }
                    windows[ch]--;
                }
            }
        }
        return res;
    }
};
// 时间复杂度为o(n),空间复杂度为o(1)
// @lc code=end

