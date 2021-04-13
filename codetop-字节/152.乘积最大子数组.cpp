/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.73%)
 * Likes:    957
 * Dislikes: 0
 * Total Accepted:    119.5K
 * Total Submissions: 291K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0],minF = nums[0],ans = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int mx = maxF,mn = minF;
            maxF = max(mx*nums[i],max(nums[i],mn*nums[i]));
            minF = min(mn*nums[i],min(nums[i],mx*nums[i]));
            ans = max(maxF , ans);
        }
        return ans;
    }
};
/*
时间复杂度：程序一次循环遍历了 nums，故渐进时间复杂度为 O(n)。
空间复杂度：优化后只使用常数个临时变量作为辅助空间，与 n 无关，故渐进空间复杂度为 O(1)。
*/
// @lc code=end

