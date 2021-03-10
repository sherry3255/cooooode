/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (48.84%)
 * Likes:    824
 * Dislikes: 0
 * Total Accepted:    69K
 * Total Submissions: 133.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix[0].length
 * 0 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution { 
public: 
    int maximalRectangle(vector<vector<char>>& matrix) { 
        int m = matrix.size(); 
        if (m == 0) { 
            return 0; 
        } 
        
        int n = matrix[0].size(); 
        vector<vector<int>> left(m, vector<int>(n, 0)); 
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++) { 
                if (matrix[i][j] == '1') { 
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1; 
                } 
            } 
        } 
        int ret = 0; 
        for (int j = 0; j < n; j++) { 
        // 对于每一列，使用基于柱状图的方法 
            vector<int> up(m, 0), down(m, 0); 
            stack<int> stk; 
            for (int i = 0; i < m; i++) { 
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) { 
                    stk.pop(); 
                } 
                up[i] = stk.empty() ? -1 : stk.top(); 
                stk.push(i); 
            } 
            stk = stack<int>(); 
            for (int i = m - 1; i >= 0; i--) { 
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop(); 
                } 
                down[i] = stk.empty() ? m : stk.top(); 
                stk.push(i); 
            } 
            for (int i = 0; i < m; i++) { 
                int height = down[i] - up[i] - 1; 
                int area = height * left[i][j]; 
                ret = max(ret, area); 
            } 
        } 
        return ret; 
    } 
};

// @lc code=end

