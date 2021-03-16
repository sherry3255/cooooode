/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (67.29%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 58.1K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i
 * - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,5,8]
 * 输出：167
 * 解释：
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,5]
 * 输出：10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        for(int i = 1; i <= n; i++){
            val[i] = nums[i - 1];
        }
        val[0] = val[n + 1] = 1;
        rec.resize(n + 2,vector<int>(n + 2, -1));
        return solve(0, n+1);
    }
    int solve(int l, int r){
        if(l >= r - 1){
            return 0;
        }
        if(rec[l][r]!=-1) return rec[l][r];
        for(int i = l+1;i<r;i++){
            int sum = val[l]*val[i]*val[r];
            sum+=solve(l,i)+solve(i,r);
            rec[l][r] = max(rec[l][r],sum);
        }
        return rec[l][r];
    }
public:
    vector<vector<int>> rec;
    vector<int> val;
};
// @lc code=end

