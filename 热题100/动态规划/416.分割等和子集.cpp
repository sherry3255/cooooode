/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.10%)
 * Likes:    684
 * Dislikes: 0
 * Total Accepted:    102.4K
 * Total Submissions: 207.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200l
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxNum = *max_element(nums.begin(),nums.end());
        if(sum % 2) return false;
        int target = sum/2;
        if(maxNum > target) return false;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i=1; i<n;i++){
            for(int j=1;j<=target;j++){
                if(j>= nums[i]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j - nums[i]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};
// @lc code=end

