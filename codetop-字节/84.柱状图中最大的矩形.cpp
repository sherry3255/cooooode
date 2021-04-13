/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution { 
public: 
    int largestRectangleArea(vector<int>& heights) { 
        heights.insert(heights.begin(), 0); 
        heights.push_back(0); 
        stack<int> st; 
        int n = heights.size(), ret = 0; 
        for (int i = 0; i < n; ++i) { 
            while (!st.empty() && heights[st.top()] > heights[i]) { 
                int back = st.top(); 
                st.pop(); 
                int left = st.empty() ? -1 : st.top(); 
                ret = max(ret, heights[back] * (i - left - 1)); 
            } 
            st.push(i); 
        } 
        return ret;  
    }
}; 
// 时间复杂度和空间复杂度均为o(n)
// 时间复杂度：O(n)。每个元素至多入栈一次，每个元素至多被扫描一次，因此复杂度为 O(n)。
// 空间复杂度：O(n)。我们需要用栈保存柱子高度，最多存储 n 个元素。

// @lc code=end

