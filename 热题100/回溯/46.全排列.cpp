/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.34%)
 * Likes:    1154
 * Dislikes: 0
 * Total Accepted:    260.1K
 * Total Submissions: 335.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution{                                                                      
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums,nums.size(),0,ans);
        return ans;
    }
    void backtrack(vector<int>& output, int len, int idx, vector<vector<int>>& ans){
        if(idx == len){
            ans.push_back(output);
        }
        for(int i = idx; i < len; i++){
            swap(output[idx],output[i]);
            backtrack(output, len, idx + 1, ans);
            swap(output[idx],output[i]);
        }
    }
};
// @lc code=end

