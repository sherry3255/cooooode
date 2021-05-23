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
/*
时间复杂度：O(S)O(S)O(S)，其中 SSS 为所有可行解的长度之和。
从分析给出的搜索树我们可以看出时间复杂度取决于搜索树所有叶子节点的深度之和，即所有可行解的长度之和。
在这题中，我们很难给出一个比较紧的上界，我们知道 O(n×2n)O(n \times 2^n)O(n×2n) 是一个比较松的上界，
即在这份代码中，nnn 个位置每次考虑选或者不选，如果符合条件，就加入答案的时间代价。
但是实际运行的时候，因为不可能所有的解都满足条件，递归的时候我们还会用 target - candidates[idx] >= 0 进行剪枝，
所以实际运行情况是远远小于这个上界的。

空间复杂度：O(target)O(\textit{target})O(target)。
除答案数组外，空间复杂度取决于递归的栈深度，在最差情况下需要递归 O(target)O(\textit{target})O(target) 层。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

