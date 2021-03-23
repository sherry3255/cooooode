/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e:nums) ret^=e;
        return ret;
    }
};
/*
    时间复杂度：O(n)，其中 n 是数组长度。只需要对数组遍历一次。
    空间复杂度：O(1)。

*/

// @lc code=end

