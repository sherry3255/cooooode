/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    690
 * Dislikes: 0
 * Total Accepted:    75.4K
 * Total Submissions: 131.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int n = prices.size();
         // f[i][0]: 手上持有股票的最大收益 
         // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益 
         // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        /*
        f0 = -prices[0];
        f1 = 0;
        f2 = 0;
        
        */
        for(int i = 1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2] - prices[i]); //当天买入
            dp[i][1] = dp[i-1][0]+prices[i]; //当天卖出
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        }
        return max(dp[n-1][1],dp[n-1][2]);

/*
        for(int i = 1;i<n;i++){
            int newf0 = max(f0,f2 - prices[i]); //当天买入
            int newf1 = f0+prices[i]; //当天卖出
            int newf2 = max(f1,f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1,f2);

*/
    }
};
/*
时间复杂度：O(n)，其中 n 为数组 prices 的长度。
空间复杂度：O(n)。我们需要 3n 的空间存储动态规划中的所有状态，对应的空间复杂度为 O(n)。如果使用空间优化，空间复杂度可以优化至 O(1)。
*/
// @lc code=end
