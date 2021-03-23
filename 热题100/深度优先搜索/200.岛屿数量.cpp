/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(nr == 0) return 0;
        int nc = grid[0].size();
        int numIslands = 0;
        for(int i = 0;i < nr;i ++){
            for(int j = 0;j < nc;j ++){
                if(grid[i][j]== '1'){
                    numIslands++;
                    dfs(grid,i,j);
                }
            }
        }
        return numIslands;
    }
private:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if(r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if(r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if(c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if(c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }
};
// 时间复杂度考虑 循环，O(nm),空间复杂度考虑dfs使用的栈的深度，最大的情况为全部都为1，为O(mn)
// @lc code=end

