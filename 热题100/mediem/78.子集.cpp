/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.38%)
 * Likes:    1019
 * Dislikes: 0
 * Total Accepted:    200.7K
 * Total Submissions: 252.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
    void dfs(int cur, vector<int>& nums){
        if(cur == nums.size()){
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur+1,nums);
        t.pop_back();
        dfs(cur+1,nums);
    }
public:
    vector<int> t;
    vector<vector<int>> ans;
};
/**
时间复杂度：O(n*2^n)。一共 2^n 个状态，每种状态需要 O(n) 的时间来构造子集。
空间复杂度：O(n)。临时数组 t 的空间代价是 O(n)，递归时栈空间的代价为 O(n)。
 * /
// @lc code=end

