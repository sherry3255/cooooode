/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.82%)
 * Likes:    795
 * Dislikes: 0
 * Total Accepted:    141.5K
 * Total Submissions: 320.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<bool>> visited(h,vector<bool>(w));
        for (int i = 0;i< h;i++){
            for(int j = 0;j < w;j ++){
                bool flag = check(board, visited, i, j, word, 0);
                if(flag) return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& s, int idx){
        if(board[i][j]!=s[idx]){
            return false;
        }else if(idx == s.length()-1){
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        bool result = false;
        for(const auto& dir:directions){
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >= 0 && newi < board.size() && newj>=0 && newj < board[0].size()){
                if(!visited[newi][newj]){
                    bool flag = check(board, visited, newi, newj, s, idx+1);
                    if(flag) return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};
/*
时间复杂度：一个非常宽松的上界为 O(MN⋅3^L)，其中 M,N 为网格的长度与宽度，L 为字符串 word的长度。在每次调用函数 check时，除了第一次可以进入 4 个分支以外，其余时间我们最多会进入 3 个分支（因为每个位置只能使用一次，所以走过来的分支没法走回去）。由于单词长为 L，故 check(i, j, 0) 的时间复杂度为 O(3^L)，而我们要执行 O(MN) 次检查。然而，由于剪枝的存在，我们在遇到不匹配或已访问的字符时会提前退出，终止递归流程。因此，实际的时间复杂度会远远小于 Θ(MN⋅3^L)

空间复杂度：O(MN)。我们额外开辟了 O(MN) 的 visited数组，同时栈的深度最大为 O(min⁡(L,MN))。
*/
// @lc code=end

