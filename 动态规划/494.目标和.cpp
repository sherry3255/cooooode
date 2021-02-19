/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    501
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 127.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 数组非空，且长度不会超过 20 。
 * 初始的数组的和不会超过 1000 。
 * 保证返回的最终结果能被 32 位整数存下。
 * 
 * 
 */a
#include <vector>
using namespace std;

// @lc code=start
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
<<<<<<< HEAD
    int result = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        
        if(nums.size()==0) return 0;
        backtrace(nums,0,S);
        return result;
    }

    void backtrace(vector<int>& nums,int i,int rest){
        if(i==nums.size()){
            if(rest==0) result++;
            return;
        }
        // -1
        rest+=nums[i];
        backtrace(nums,i+1,rest);
        rest-=nums[i];

        // +1
        rest-=nums[i];
        backtrace(nums,i+1,rest);
        rest+=nums[i];
=======
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) sum += n;
        // 这两种情况，不可能存在合法的子集划分
        if (sum < target || (sum + target) % 2 == 1) {
            return 0;
        }
        return subsets(nums, (sum + target) / 2);
    }

    int subsets(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector(sum+1,0));
        // base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
>>>>>>> 3029aadfc1a0f850e1dec101f16b076f606d9dce

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= nums[i-1]) {
                    // 两种选择的结果之和
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    // 背包的空间不足，只能选择不装物品 i
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};



// 备忘录

// @lc code=end

