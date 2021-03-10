/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (53.61%)
 * Likes:    2074
 * Dislikes: 0
 * Total Accepted:    198.9K
 * Total Submissions: 365.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int ans = 0;
        int l_max = 0, r_max = 0;
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= l_max ? (l_max = height[left]) : ans += (l_max - height[left]);
                left ++; 
            }else{
                height[right] >= r_max ? (r_max = height[right]) : ans += (r_max - height[right]);
                right --;
            }
        }
        return ans;
    }
};
// @lc code=end

