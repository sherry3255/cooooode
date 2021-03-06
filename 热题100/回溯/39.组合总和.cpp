/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (71.78%)
 * Likes:    1178
 * Dislikes: 0
 * Total Accepted:    211.3K
 * Total Submissions: 293.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combine;
        vector<vector<int>> ans;
        dfs(candidates, target, 0, ans, combine);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int idx, vector<vector<int>>& ans, vector<int>& combine){
        if(idx == candidates.size()) return;
        if(target == 0){
            ans.push_back(combine);
            return;
        }
        dfs(candidates, target, idx + 1, ans, combine);
        if(target - candidates[idx] >= 0){
            combine.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], idx, ans, combine);
            combine.pop_back();
        }
    }
};
// @lc code=end

