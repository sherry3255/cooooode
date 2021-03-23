/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.90%)
 * Likes:    794
 * Dislikes: 0
 * Total Accepted:    183K
 * Total Submissions: 268.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int r = grid.size();
        int c = grid[0].size();
        // vector<vector<int>> dp(r, vector<int>(c));
        // 可使用grid[i][j]直接覆盖，因为每次grid[i][j]也只被访问一次即可
        // dp[0][0] = grid[0][0];
        for(int i = 1;i<r;i++){
            grid[i][0] = grid[i- 1][0] + grid[i][0];
        }
        for(int j = 1;j<c;j++){
            grid[0][j] = grid[0][j-1] + grid[0][j];
        }
        for(int i = 1;i<r;i++){
            for(int j =1;j<c;j++){
                grid[i][j] = min(grid[i][j-1],grid[i-1][j]) + grid[i][j];
            }
        }
        return grid[r-1][c-1];

    }
};
// @lc code=end

