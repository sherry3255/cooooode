/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution { 
private: 
    vector<vector<int>> edges; 
    vector<int> visited; 
    bool valid = true; 
public: 
    void dfs(int u) { 
        visited[u] = 1; 
        for (int v: edges[u]) { 
            if (visited[v] == 0) { 
                dfs(v); 
                if (!valid) { 
                    return; 
                } 
            } 
            else if (visited[v] == 1) { 
                valid = false; return; 
            } 
        } 
        visited[u] = 2; 
    } 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        edges.resize(numCourses); 
        visited.resize(numCourses); 
        for (const auto& info: prerequisites) { 
            edges[info[1]].push_back(info[0]); 
        } 
        for (int i = 0; i < numCourses && valid; ++i) { 
            if (!visited[i]) { 
                    dfs(i); 
            } 
        } 
        return valid; 
    } 
};
/*
时间复杂度: O(n+m)，其中 n 为课程数，m 为先修课程的要求数。这其实就是对图进行深度优先搜索的时间复杂度。
空间复杂度: O(n+m)。题目中是以列表形式给出的先修课程关系，为了对图进行深度优先搜索，我们需要存储成邻接表的形式，空间复杂度为 O(n+m)。在深度优先搜索的过程中，我们需要最多 O(n) 的栈空间（递归）进行深度优先搜索，因此总空间复杂度为 O(n+m)。

*/
// @lc code=end

